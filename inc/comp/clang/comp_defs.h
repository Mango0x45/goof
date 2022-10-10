/**
 * =============================================
 * comp/clang/comp_defs.h: Clang-specific stuff.
 * =============================================
 * 
 * Note: comp/gnu/comp_defs.h can be used as a fallback for this file.
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

    #define __assume__(a) (__attribute__((assume(a))))
    #define __maybe_unused__ (__attribute__((unused)))
    #define __deprecated__(r) (__attribute__((deprecated(r))))
    #define __fallthrough__ (__attribute__((fallthrough)))
    #define __always_inline__ (__attribute__((always_inline)))
    #define __noreturn_ (__attribute__((noreturn)))
    #define __pure_ (__attribute__((pure)))
    #define __packed_ (__attribute__((packed)))
#endif

#endif /* include guard */