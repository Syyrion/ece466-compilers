#ifndef ERRORF_H
#define ERRORF_H

#include <stdio.h>
#include <stdlib.h>

#define log(format, ...) \
    fprintf(stderr, format "\n" __VA_OPT__(, ) __VA_ARGS__)

#define errorf(...)         \
    do                      \
    {                       \
        log(__VA_ARGS__);   \
        exit(EXIT_FAILURE); \
    } while (0)

#endif