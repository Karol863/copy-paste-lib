#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h>

#include "base.h"

#define RESERVED_SIZE 4294967296 // 4GB
#define PAGE_SIZE 4096

typedef struct {
    void *data;
    isize offset;
    isize commited;
    isize available;
} Arena;

#endif // ARENA_H
