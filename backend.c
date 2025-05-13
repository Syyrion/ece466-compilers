#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ast.h"
#include "quad.h"
#include "errorf.h"

FILE *backend_file;

/*
Accessing global variables

Accessing local variables including stack frame allocation
Computation of expressions
Reading and writing array elements
Dereferencing pointers and taking address-of
String constants
Control flow (if statements and at least one type of loop)
Calling external function, with arguments (int or pointer)
*/

enum section
{
    NONE,
    DATA,
    RODATA,
    TEXT,
};

enum section current_section = NONE;

void change_section(enum section new_section)
{
    if (new_section == current_section)
        return;
    switch (new_section)
    {
    case DATA:
        fprintf(backend_file, "\t.data\n");
        break;
    case RODATA:
        fprintf(backend_file, "\t.section\t.rodata\n");
        break;
    case TEXT:
        fprintf(backend_file, "\t.text\n");
        break;
    default:
        break;
    }
    current_section = new_section;
}

unsigned long string_lit_counter = 0;

void backend_begin(void)
{
    backend_file = fopen("output/assembly.s", "w+");
}

void backend_write_global(ast_node_t *var)
{
    change_section(DATA);
    switch (var->next->kind)
    {
    case AST_TYPE:
    case AST_POINTER:
        fprintf(backend_file, "\t.globl %s\n", var->name);
        fprintf(backend_file, "%s:\n\t.long 4\n", var->name);
        break;
    case AST_ARRAY:
        fprintf(backend_file, "\t.globl %s\n", var->name);
        fprintf(backend_file, "%s:\n\t.zero %d\n", var->name, ast_get_sizeof_value(var->next));
        break;
    default:
        break;
    }
}

static void backend_print_string_literal(ast_node_t *string)
{
    char *s = string->string_literal.buffer;
    for (int i = 0; s[i] != 0; i++)
    {
        if (s[i] == '\x07')
            fprintf(backend_file, "\\a");
        else if (s[i] == '\x08')
            fprintf(backend_file, "\\b");
        else if (s[i] == '\x0c')
            fprintf(backend_file, "\\f");
        else if (s[i] == '\x0a')
            fprintf(backend_file, "\\n");
        else if (s[i] == '\x0d')
            fprintf(backend_file, "\\r");
        else if (s[i] == '\x09')
            fprintf(backend_file, "\\t");
        else if (s[i] == '\x0b')
            fprintf(backend_file, "\\v");
        else if (s[i] == '\\')
            fprintf(backend_file, "\\\\");
        else if (s[i] == '\'')
            fprintf(backend_file, "\\\'");
        else if (s[i] == '"')
            fprintf(backend_file, "\\\"");
        else if (s[i] == 0)
            fprintf(backend_file, "\\0");
        else if (isprint(s[i]))
            fputc(s[i], backend_file);
        else
            fprintf(backend_file, "\\%03o", (unsigned char)s[i]);
    }
}

void backend_write_function(basic_block_list_t *fn, char *name)
{
    if (fn->string_literal_list->count > 0)
    {
        change_section(RODATA);
        ENUMERATE(fn->string_literal_list, i, {
            fprintf(backend_file, ".LC%d:\n\t.string \"", string_lit_counter + i);
            backend_print_string_literal(fn->string_literal_list->items[i]);
            fprintf(backend_file, "\"\n");
        });
    }

    change_section(TEXT);
    fprintf(backend_file, "\t.globl	%s\n"
                          "\t.type	%s, @function\n"
                          "%s:\n",
            name, name, name);

    // function enter
    fprintf(backend_file, "\tpushl   %%ebp\n"
                          "\tmovl    %%esp, %%ebp\n");

    // make space for local vars
    fprintf(backend_file, "\tsubl $%d, %%esp\n", (fn->temp_var_count + fn->variable_count) * 4);

    fprintf(backend_file, "# temp: %d, local: %d, args: %d\n", fn->temp_var_count, fn->variable_count, fn->argument_count);

    char source1[128];
    char source2[128];
    char dest[128];

    for (int i = 0; i < fn->count; i++)
    {
        basic_block_t *bb = fn->items[i];

        fprintf(backend_file, "__%s_BB%d:\n", name, i);

        for (int j = 0; j < bb->count; j++)
        {
            bquad_t *q = bb->items[j];
            fprintf(backend_file, "# %s\n", op_names[q->op]);
            switch (q->op)
            {
            case NOP:
                break;
            case MOV:
                switch (q->dest->kind)
                {
                case AST_VARIABLE:
                    if (q->dest->variable.storage_class == SC_EXTERN)
                        snprintf(dest, sizeof(dest), "$%s", q->dest->variable.name);
                    else
                        snprintf(dest, sizeof(dest), "%d(%%esp)", (fn->temp_var_count + q->dest->variable.num) * 4);
                    break;
                case AST_TEMPORARY:
                    snprintf(dest, sizeof(dest), "%d(%%esp)", (q->dest->temporary.num) * 4);
                    break;
                default:
                    errorf("invalid quad");
                }

                switch (q->arg1->kind)
                {
                case AST_NUMBER_LITERAL:
                    snprintf(source1, sizeof(source1), "$%d", q->arg1->number_literal.integer);
                    break;
                case AST_VARIABLE:
                    if (q->arg1->variable.storage_class == SC_EXTERN)
                        snprintf(source1, sizeof(source1), "$%s", q->arg1->variable.name);
                    else
                    {
                        if (q->arg1->variable.is_argument)
                            snprintf(source1, sizeof(source1), "%d(%%ebp)", 4 + (fn->temp_var_count + q->arg1->variable.num) * 4);
                        else
                            snprintf(source1, sizeof(source1), "%d(%%esp)", (fn->temp_var_count + q->arg1->variable.num) * 4);
                    }

                    break;
                case AST_TEMPORARY:
                    snprintf(source1, sizeof(source1), "%d(%%esp)", (q->arg1->temporary.num) * 4);
                    break;
                default:
                    errorf("invalid quad");
                }
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETP:

                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetg %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETNP:
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetle %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETM:
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetl %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETNM:
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetge %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETZ:
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetz %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETNZ:
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetnz %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;

            case LEA:
                // switch (q->dest->kind)
                // {
                // case AST_VARIABLE:
                //     if (q->dest->variable.storage_class == SC_EXTERN)
                //         snprintf(dest, sizeof(dest), "$%s", q->dest->variable.name);
                //     else
                //         snprintf(dest, sizeof(dest), "%d(%%esp)", (fn->temp_var_count + q->dest->variable.num) * 4);
                //     break;
                // case AST_TEMPORARY:
                //     snprintf(dest, sizeof(dest), "%d(%%esp)", (q->dest->temporary.num) * 4);
                //     break;
                // default:
                //     errorf("invalid quad");
                // }
                // switch (q->arg1->kind)
                // {
                // case AST_NUMBER_LITERAL:
                //     snprintf(source, sizeof(source), "$%d", q->arg1->numberlit.signed_integer);
                //     break;
                // case AST_VARIABLE:
                //     if (q->arg1->variable.storage_class == SC_EXTERN)
                //         snprintf(source, sizeof(source), "$%s", q->arg1->variable.name);
                //     else
                //         snprintf(source, sizeof(source), "%d(%%esp)", (fn->temp_var_count + q->arg1->variable.num) * 4);
                //     break;
                // case AST_STRING_LITERAL:
                //     snprintf(source, sizeof(source), "%d(%%esp)", (q->arg1->temporary.num) * 4);
                //     break;
                // default:
                //     errorf("invalid quad");
                // }

                // fprintf(backend_file, "\tmovl %s, %%eax\n", source);
                // fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case LOAD:
                break;
            case STORE:
                break;
            case ADD:
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\taddl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SUB:
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tsubl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case MUL:
                fprintf(backend_file, "\tmovl %s, %%edx\n", source1);
                fprintf(backend_file, "\tmovl %s, %%eax\n", source2);
                fprintf(backend_file, "\timull %%edx, %%eax\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case DIV:
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tcltd\n");
                fprintf(backend_file, "\tidivl %%ecx\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case MOD:
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tcltd\n");
                fprintf(backend_file, "\tidivl %%ecx\n");
                fprintf(backend_file, "\tmovl %%edx, %s\n", dest);
                break;
            case NEG:
                break;
            case SL:
                break;
            case SR:
                break;
            case CPL:
                break;
            case AND:
                break;
            case OR:
                break;
            case XOR:
                break;
            case CMP:
                fprintf(backend_file, "\tmovl %s, %%ebx\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tcmp %%ecx, %%ebx\n");
                break;
            case ARGBEGIN:
                break;
            case ARG:
                break;
            case CALL:
                // move value in eax to destination
                break;
            case RET:
                // move result to eax if it's there
                fprintf(backend_file, "\tleave\n"
                                      "\tret\n");
                break;
            case JP:
                fprintf(backend_file, "\tjmp $%s\n", source1);
                break;
            case JPP:
                fprintf(backend_file, "\tjg $%s\n", source1);
                break;
            case JPNP:
                fprintf(backend_file, "\tjle $%s\n", source1);
                break;
            case JPM:
                fprintf(backend_file, "\tjl $%s\n", source1);
                break;
            case JPNM:
                fprintf(backend_file, "\tjge $%s\n", source1);
                break;
            case JPZ:
                fprintf(backend_file, "\tjz $%s\n", source1);
                break;
            case JPNZ:
                fprintf(backend_file, "\tjnz $%s\n", source1);
                break;
            default:
                break;
            }
        }
    }

    string_lit_counter += fn->string_literal_list->count;
}

void backend_end(void)
{
    fclose(backend_file);
    backend_file = 0;
}
