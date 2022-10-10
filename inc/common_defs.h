/**
 * ===============================================
 * common/common_defs.h: general goof definitions.
 * ===============================================
 * 
 * Includes all other *_defs.h headers.
 */

#ifndef __COMMON_DEFS_H
#define __COMMON_DEFS_H "common/common_defs.h"

#include "comp_defs.h"
#include "arch_defs.h"
#include "os_defs.h"
#include "internal_types.h"

/* I'm considering including int.h in here as well. */

#define NULL ((void*)0)

#if __STDC_VERSION__ < 202000L /* C23 will define these as keywords */
    #define alignas(e) _Alignas(e)
    #define alignof(e) _Alignof(e)
    
    #define bool _Bool
    #define true ((_Bool)1)
    #define false ((_Bool)0)

    typedef __nullptr_t nullptr_t;
    #define nullptr ((__nullptr_t)0)
#endif

#define complex _Complex
#define imaginary _Imaginary

/** Unsigned integral type capable of storing the size of any type. */
typedef __size_t        size_t;
/** Signed integral type capable of storing the difference of two pointers. */
typedef __ptrdiff_t     ptrdiff_t;
/** A type with alignment requirement at least as large as any scalar type. */
typedef __max_align_t   max_align_t;


/* Utility macros. They're just nice to have. */

/** Expands the argument and then stringifies it. */
#define STRINGIFY(e) _STRINGIFY(e)
#define _STRINGIFY(e) #e

/**
 * Expands to 10 if argument expression expands to something, 0 otherwise.
 * Useful to test difference between a macro that is defined as 0 and one that
 * is just defined, or to test a conditionaly defined macro.
 */
#define NONEMPTY(...) _NONEMPTY(__VA_OPT__(1))
#define _NONEMPTY(...) __VA_OPT__(1) ## 0

#endif /* include guard */