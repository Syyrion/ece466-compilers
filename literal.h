#ifndef LITERAL_H
#define LITERAL_H

#include "declarations.h"

// string literal value
typedef struct string
{
    char *buffer;
    unsigned long long length;
    unsigned long long size;
} string_t;

// number literal value
typedef struct number
{
    union
    {
        unsigned long long integer;
        long double real;
    };
    scalar_t type;
} number_t;

#endif