#ifndef BASE_H
#define BASE_H

#include <stdint.h>
#include <stddef.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef size_t usize;
typedef ptrdiff_t isize;
typedef uintptr_t uptr;
typedef intptr_t sptr;

#ifdef __GNUC__
    #define ASSERT(X) ((X) ? (void)0 : __builtin_trap())
#else
    #define ASSERT(X) ((X) ? (void)0 : (void)(*(volatile int *)0 = 0))
#endif

#if !defined(bool) && !defined(__cplusplus) && __STDC_VERSION__ <= 201710L
typedef u8 bool;
enum {
	false = 0,
	true = 1,
};
#endif

typedef struct {
    u8 *str;
    isize len;
} String;

#define STR(X)              (String){(u8*)X, SIZEOF(X)-1}
#define UNUSED(X)           (void)(X)
#define SIZEOF(X)           ((isize)sizeof(X))
#define ARRLEN(X)           (SIZEOF(X) / SIZEOF(0[X]))
#define MIN(A, B)           (((A) < (B) ) ? (A) : (B))
#define MAX(A, B)           (((A) > (B) ) ? (A) : (B))
#define CLAMP(V, LO, HI)    (((V) < (LO)) ? (LO) : ((V) > (HI)) ? (HI) : (V))

#endif // BASE_H
