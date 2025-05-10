#include "macro_kit.h"

// macro parameters

// list prefix
#ifndef LIST_CONTENT_NAME
#error list.inl needs LIST_CONTENT_NAME to be defined
#endif

// data type that the list contains (no arrays)
#ifndef LIST_CONTENT_TYPE
#error list.inl needs LIST_CONTENT_TYPE to be defined
#endif

// additional members to add to the list structure
#ifndef LIST_ADDITIONAL_MEMBERS
#define LIST_ADDITIONAL_MEMBERS
#endif

#define LIST_TYPEDEF_NAME JOIN2(LIST_CONTENT_NAME, list_t)
#define LIST_CONTENT_TYPEDEF_NAME CAT2(__, JOIN2(LIST_TYPEDEF_NAME, content))

typedef LIST_CONTENT_TYPE LIST_CONTENT_TYPEDEF_NAME;
typedef struct CAT2(__, JOIN2(LIST_CONTENT_NAME, list))
{
    unsigned long capacity;
    unsigned long count;
    LIST_CONTENT_TYPEDEF_NAME *items;
    LIST_ADDITIONAL_MEMBERS
} LIST_TYPEDEF_NAME;

#define LIST_NEW JOIN2(LIST_CONTENT_NAME, list_new)
#define LIST_ADD JOIN2(LIST_CONTENT_NAME, list_add)
#define LIST_FREE JOIN2(LIST_CONTENT_NAME, list_free)

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

#ifndef LIST_INL_ENUMERATOR
#define LIST_INL_ENUMERATOR

#define ENUMERATE(list, index, statement)                           \
    do                                                              \
    {                                                               \
        for (unsigned long index = 0; index < list->count; index++) \
            statement                                               \
    } while (0)

#endif

#undef LIST_CONTENT_NAME
#undef LIST_CONTENT_TYPE
#undef LIST_ADDITIONAL_MEMBERS

#undef LIST_TYPEDEF_NAME
#undef LIST_CONTENT_TYPEDEF_NAME
#undef LIST_NEW
#undef LIST_ADD
#undef LIST_FREE