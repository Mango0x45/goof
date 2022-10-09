/**
 * ==========================================================
 * os/linux/x86_64/internal_types.h: internal type definitions.
 * ==========================================================
 * Types that all other types build upon.
 *
 * We define the following internal types:
 * __[s/u]intN_t:		8,16,32,64-bit wide [un]signed integers.
 * __[s/u]intmax_t:		integers of maximum width supported by the platform.
 * __[s/u]intword_t:	integers of the same width as the platform word.
 * __[s/u]intptr_t:		integer capable of storing a pointer (void*).
 * __size_t:        	unsigned integral type capable of storing the size of
 * 						any type.
 * __ptrdiff_t:     	signed integral type capable of storing the difference
 * 						of two pointers.
 *
 */

#ifndef __INTERNAL_TYPES_H
#define __INTERNAL_TYPES_H "os/linux/x86_64/internal_types.h"

#include "arch_defs.h"

#ifndef __LP64__
#error "Wrong internal_types.h file! This is linux/x86_64."
#endif

#if __CHAR_BIT__ != 8
#error "Platform does not have 8-bit bytes! Goof out."
#endif

typedef signed char __schar_t;
typedef unsigned char __uchar_t;

typedef signed char __sint8_t;
typedef unsigned char __uint8_t;

typedef signed short int __sint16_t;
typedef unsigned short int __uint16_t;

typedef signed int __sint32_t;
typedef unsigned int __uint32_t;

typedef signed long int __sint64_t;
typedef unsigned long int __uint64_t;

typedef signed long long int __sintmax_t;
typedef unsigned long long int __uintmax_t;

typedef signed long int __sintptr_t;
typedef unsigned long int __uintptr_t;

typedef signed long int __sintword_t;
typedef unsigned long int __uintword_t;

typedef __sintword_t __size_t;
typedef __uintword_t __ptrdiff_t;

#if __STDC_VERSION__ < 202000L
    typedef void* __nullptr_t;
#else
    typedef __typeof__(nullptr) __nullptr_t;
#endif

#define SINTMAX_T_WIDTH     64
#define UINTMAX_T_WIDTH     64
#define SINTPTR_T_WIDTH     __WORDSIZE
#define UINTPTR_T_WIDTH     __WORDSIZE
#define SINTWORD_T_WIDTH    __WORDSIZE
#define UINTWORD_T_WIDTH    __WORDSIZE
#define SIZE_T_WIDTH        __WORDSIZE
#define PTRDIFF_T_WIDTH     __WORDSIZE

#define __INT8_MAX          (127)
#define __INT8_MIN          (-128)
#define __UINT8_MAX         (255U)

#define __INT16_MAX         (32767)
#define __INT16_MIN         (-32768)
#define __UINT16_MAX        (65535U)

#define __INT32_MAX         (2147483647)
#define __INT32_MIN         (-2147483648)
#define __UINT32_MAX        (4294967295U)

#define __INT64_MAX         (9223372036854775807L)
#define __INT64_MIN         (-9223372036854775808L)
#define __UINT64_MAX        (18446744073709551615UL)

#define __INTMAX_MAX        (9223372036854775807LL)
#define __INTMAX_MIN        (-9223372036854775808LL)
#define __UINTMAX_MAX       (18446744073709551615ULL)

# define __INTWORD_MAX      (9223372036854775807L)
# define __INTWORD_MIN      (-9223372036854775808L)
# define __UINTWORD_MAX     (18446744073709551615UL)

#define __INTPTR_MAX        __INTWORD_MAX
#define __INTPTR_MIN        __INTWOD_MIN
#define __UINTPTR_MAX       __UINTWOD_MAX

#define __PTRDIFF_MAX		__INTWORD_MAX
#define __PTRDIFF_MIN		__INTWORD_MIN
#define __SIZE_T_MAX		__UINTWORD_MAX

#endif

