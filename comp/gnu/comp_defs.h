/**
 * =========================================
 * comp/gnu/comp_defs.h: GNU-specific stuff.
 * =========================================
 */

#ifndef __COMP_DEFS_H
#define __COMP_DEFS_H "comp/gnu/comp_defs.h"

#ifndef __GNUC__
#error "Wrong comp_defs.h file! This is gnu."
#elif defined __clang__
#warning "Using gnu/comp_defs.h with __clang__ defined!"
#endif

#define offsetof(t, d) __builtin_offsetof(t, d)

#if __STDC_VERSION__ < 202000L
    #define typeof(x) __typeof__(x)
    #define unreachable() (__builtin_unreachable())
#endif

#endif /* include guard */