/**
 * =============================================
 * comp/clang/comp_defs.h: Clang-specific stuff.
 * =============================================
 */

#ifndef __COMP_DEFS_H
#define __COMP_DEFS_H "comp/clang/comp_defs.h"

#ifndef __clang__
#error "Wrong comp_defs.h file! This is clang."
#endif

#define offsetof(t, d) __builtin_offsetof(t, d)

#if __STDC_VERSION__ < 202000L
    #define typeof(x) __typeof__(x)
    #define unreachable() (__builtin_unreachable())
#endif

#endif /* include guard */