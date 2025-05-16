#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ast.h"
#include "quad.h"
#include "errorf.h"

FILE *backend_file;

/*
Reading and writing array elements
Dereferencing pointers and taking address-of
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

void backend_begin(void)
{
    backend_file = fopen("output/assembly.s", "w+");
}

void backend_write_global(ast_node_t *var)
{
    change_section(DATA);
    if (var->variable.storage_class == SC_IMPLICIT_EXTERN)
        fprintf(backend_file, "\t.globl %s\n", var->name);
    switch (var->next->kind)
    {
    case AST_TYPE:
    case AST_POINTER:
        fprintf(backend_file, "%s:\n\t.long 0\n", var->name);
        break;
    case AST_ARRAY:
        fprintf(backend_file, "\t.comm %s, %d\n", var->name, ast_get_sizeof_value(var->next));
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

static void locate_value(ast_node_t *val, char *b, unsigned long size, basic_block_list_t *fn)
{

    switch (val->kind)
    {
    case AST_STRING_LITERAL:
        snprintf(b, size, "$.LC_%s_%d", fn->name, val->string_literal.num);
        break;
    case AST_NUMBER_LITERAL:
        snprintf(b, size, "$%d", val->number_literal.integer);
        break;
    case AST_VARIABLE:
        if (val->variable.storage_class == SC_EXTERN || val->variable.storage_class == SC_IMPLICIT_EXTERN)
        {
            snprintf(b, size, "%s", val->variable.name);
        }
        else if (val->variable.is_argument)
        {
            snprintf(b, size, "%d(%%ebp)", (val->variable.num + 2) * 4);
        }
        else // regular local variable
        {
            snprintf(b, size, "%d(%%ebp)", (fn->temp_var_count + val->variable.num + 1) * -4);
        }
        break;
    case AST_TEMPORARY:
        snprintf(b, size, "%d(%%ebp)", (val->temporary.num + 1) * -4);
        break;
    default:
        errorf("invalid quad");
    }
}

void backend_write_function(basic_block_list_t *fn)
{
    char *name = fn->name;
    if (fn->string_literal_list->count > 0)
    {
        change_section(RODATA);
        ENUMERATE(fn->string_literal_list, i, {
            fprintf(backend_file, ".LC_%s_%d:\n\t.string \"", name, i);
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

    int call_stack_size;
    char source1[128];
    char source2[128];
    char dest[128];

#define LD locate_value(q->dest, dest, sizeof(dest), fn)
#define LS1 locate_value(q->arg1, source1, sizeof(source1), fn)
#define LS2 locate_value(q->arg2, source2, sizeof(source2), fn)
#define J snprintf(source1, sizeof(source1), "__%s_BB%d\n", name, q->jump_target)

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
                LD;
                LS1;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETP:
                LD;
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetg %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETNP:
                LD;
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetle %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETM:
                LD;
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetl %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETNM:
                LD;
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetge %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETZ:
                LD;
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetz %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SETNZ:
                LD;
                fprintf(backend_file, "\tmovl $0, %%eax\n");
                fprintf(backend_file, "\tsetnz %%al\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case LEA:
                LD;
                LS1;

                ast_node_t *val = q->arg1;
                switch (val->kind)
                {
                case AST_STRING_LITERAL:
                    fprintf(backend_file, "\tmovl %s, %s\n", source1, dest);
                    break;
                case AST_VARIABLE:
                    if (val->variable.storage_class == SC_EXTERN || val->variable.storage_class == SC_IMPLICIT_EXTERN)
                    {
                        fprintf(backend_file, "\tmovl $%s, %s\n", source1, dest);
                    }
                    else
                    {
                    temp:
                        fprintf(backend_file, "\tleal %s, %%eax\n", source1);
                        fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                    }
                    break;
                case AST_TEMPORARY:
                    goto temp;
                default:
                    errorf("invalid quad");
                }

                break;
            case LOAD:
                LD;
                LS1;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl (%%eax), %%ecx\n", dest);
                fprintf(backend_file, "\tmovl %%ecx, %s\n", dest);
                break;
            case STORE:
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tmovl %%eax, (%%ecx)\n");
                break;
            case ADD:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\taddl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SUB:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tsubl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case MUL:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%edx\n", source1);
                fprintf(backend_file, "\tmovl %s, %%eax\n", source2);
                fprintf(backend_file, "\timull %%edx, %%eax\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case DIV:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tcltd\n");
                fprintf(backend_file, "\tidivl %%ecx\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case MOD:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tcltd\n");
                fprintf(backend_file, "\tidivl %%ecx\n");
                fprintf(backend_file, "\tmovl %%edx, %s\n", dest);
                break;
            case NEG:
                LD;
                LS1;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\nnegl %%eax\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SL:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tsall %%cl, %%eax\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case SR:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tsarl %%cl, %%eax\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case CPL:
                LD;
                LS1;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\nnotl %%eax\n");
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case AND:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tandl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case OR:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\torl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case XOR:
                LD;
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\txorl %s, %%eax\n", source2);
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case CMP:
                LS1;
                LS2;
                fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                fprintf(backend_file, "\tmovl %s, %%ecx\n", source2);
                fprintf(backend_file, "\tcmp %%ecx, %%eax\n");
                break;
            case ARGBEGIN:
                call_stack_size = 0;
                break;
            case ARG:
                LS1;
                call_stack_size += 4;
                fprintf(backend_file, "\tpushl %s\n", source1);
                break;
            case CALL:
                // move value in eax to destination
                if (q->arg1->kind == AST_IDENT || q->arg1->kind == AST_VARIABLE)
                    snprintf(source1, sizeof(source1), "%s", q->arg1->name);
                else
                    errorf("invalid call quad");

                fprintf(backend_file, "\tcall %s\n", source1);
                LD;
                if (call_stack_size > 0)
                    fprintf(backend_file, "\taddl $%d, %%esp\n", call_stack_size); // drop the stack pointer
                fprintf(backend_file, "\tmovl %%eax, %s\n", dest);
                break;
            case RET:
                if (q->arg1)
                {
                    LS1;
                    fprintf(backend_file, "\tmovl %s, %%eax\n", source1);
                }
                fprintf(backend_file, "\tleave\n"
                                      "\tret\n");
                break;
            case JP:
                J;
                fprintf(backend_file, "\tjmp %s\n", source1);
                break;
            case JPP:
                J;
                fprintf(backend_file, "\tjg %s\n", source1);
                break;
            case JPNP:
                J;
                fprintf(backend_file, "\tjle %s\n", source1);
                break;
            case JPM:
                J;
                fprintf(backend_file, "\tjl %s\n", source1);
                break;
            case JPNM:
                J;
                fprintf(backend_file, "\tjge %s\n", source1);
                break;
            case JPZ:
                J;
                fprintf(backend_file, "\tjz %s\n", source1);
                break;
            case JPNZ:
                J;
                fprintf(backend_file, "\tjnz %s\n", source1);
                break;
            default:
                break;
            }
        }
    }
}

void backend_end(void)
{
    fclose(backend_file);
    backend_file = 0;
}
