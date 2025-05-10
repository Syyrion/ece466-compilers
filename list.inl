#include "macro_kit.h"

// list prefix
#ifndef LIST_NAME
#error list.inl needs LIST_NAME to be defined
#endif

#define LIST_STRUCT_NAME JOIN2(__LX, LIST_NAME)
#define LIST_TYPEDEF_NAME JOIN2(LIST_NAME, t)

#ifdef LIST_FORWARD_DECLARE // define to set forward declare mode

struct LIST_STRUCT_NAME;
typedef struct LIST_STRUCT_NAME LIST_TYPEDEF_NAME;

#else

// data type that the list contains (no arrays)
#ifndef LIST_CONTENT_TYPE
#error list.inl needs LIST_CONTENT_TYPE to be defined
#endif

// additional members to add to the list structure
#ifndef LIST_ADDITIONAL_MEMBERS
#define LIST_ADDITIONAL_MEMBERS
#endif

#define LIST_CONTENT_TYPEDEF_NAME JOIN3(__LX, LIST_NAME, content)

typedef LIST_CONTENT_TYPE LIST_CONTENT_TYPEDEF_NAME;
typedef struct LIST_STRUCT_NAME
{
    unsigned long capacity;
    unsigned long count;
    LIST_CONTENT_TYPEDEF_NAME *items;
    LIST_ADDITIONAL_MEMBERS
} LIST_TYPEDEF_NAME;

#define LIST_NEW JOIN2(LIST_NAME, new)
#define LIST_ADD JOIN2(LIST_NAME, add)
#define LIST_FREE JOIN2(LIST_NAME, free)

extern LIST_TYPEDEF_NAME *LIST_NEW(void);
extern LIST_TYPEDEF_NAME *LIST_ADD(LIST_TYPEDEF_NAME *list, LIST_CONTENT_TYPEDEF_NAME item);
extern void LIST_FREE(LIST_TYPEDEF_NAME *list);

#ifdef LIST_IMPLEMENT

// Makes a new generic ast list
extern LIST_TYPEDEF_NAME *LIST_NEW(void)
{
    LIST_TYPEDEF_NAME *new_inst = calloc(1, sizeof(LIST_TYPEDEF_NAME));
    return new_inst;
}

// Appends an ast node to an ast list
extern LIST_TYPEDEF_NAME *LIST_ADD(LIST_TYPEDEF_NAME *list, LIST_CONTENT_TYPEDEF_NAME item)
{
    if (list->items)
    {
        if (list->count == list->capacity)
            list->items = realloc(list->items, (list->capacity *= 2) * sizeof(LIST_CONTENT_TYPEDEF_NAME));
    }
    else
    {
        list->capacity = 1;
        list->items = malloc(sizeof(LIST_CONTENT_TYPEDEF_NAME));
    }
    list->items[list->count++] = item;
    return list;
}

// Frees a node list. Does not free any contained nodes.
extern void LIST_FREE(LIST_TYPEDEF_NAME *list)
{
    if (list->items)
        free(list->items);
    free(list);
}

#endif

// works for any list
#ifndef LIST_INL_ENUMERATOR
#define LIST_INL_ENUMERATOR

#define ENUMERATE(list, index, statement)                           \
    do                                                              \
    {                                                               \
        for (unsigned long index = 0; index < list->count; index++) \
            statement                                               \
    } while (0)

#endif

#endif // LIST_FORWARD_DECLARE

#undef LIST_NAME
#undef LIST_CONTENT_TYPE
#undef LIST_FORWARD_DECLARE
#undef LIST_ADDITIONAL_MEMBERS

#undef LIST_TYPEDEF_NAME
#undef LIST_STRUCT_NAME
#undef LIST_CONTENT_TYPEDEF_NAME
#undef LIST_NEW
#undef LIST_ADD
#undef LIST_FREE