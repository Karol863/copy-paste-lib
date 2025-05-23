#include "arena.h"

void arena_init(Arena *a) {
    a->data = mmap(NULL, RESERVED_SIZE, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (a->data == MAP_FAILED) {
        fputs("ERROR: Failed to reserve memory for the arena.\n", stderr);
        exit(1);
    }
    a->offset = 0;
    a->commited = 0;
    a->available = RESERVED_SIZE;
}

void *arena_alloc(Arena *a, isize size) {
    ASSERT(size > 0);
    if (a->offset + size >= a->commited) {
        isize mem_to_commit = (size + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1);
        ASSERT(mem_to_commit > 0);

        if (a->commited + mem_to_commit > a->available) {
            fputs("ERROR: Arena is full.\n", stderr);
            exit(1);
        }

        if (mprotect((u8 *)a->data + a->commited, mem_to_commit, PROT_READ | PROT_WRITE) == -1) {
            fputs("ERROR: Failed to commit memory for the arena.\n", stderr);
            exit(1);
        }

        a->commited += mem_to_commit;
    }
    void *p = (u8 *)a->data + a->offset;
    a->offset += size;

    ASSERT(p != NULL);
    return p;
}

void arena_reset(Arena *a) {
    a->offset = 0;
}
