/**
 * ===========================================
 * comp/msvc/comp_defs.h: MSVC-specific stuff.
 * ===========================================
 */

#ifndef __COMP_DEFS_H
#define __COMP_DEFS_H "comp/msvc/comp_defs.h"

#ifndef _MSC_VER
#error "Wrong comp_defs.h file! This is msvc."
#endif

#include "internal_types.h"

// idk for sure how MS handles offsetof
#define offsetof(s, m) ((__size_t)((const char*)(((s*)0)->m)))

#if __STDC_VERSION__ < 202000L
    #define typeof(x) decltype(x)
    #define unreachable() (__assume(0))

    #define __assume__(a) (__assume(a))
    #define __maybe_unused__ (__declspec((maybe_unused)))
    #define __deprecated__ (__declspec((deprecated)))
    #define __fallthrough__ (__declspec((fallthrough)))
    #define __always_inline__ (__declspec((noreturn)))
    #define __nodiscard_ (__declspec((nodiscard)))
#endif

#endif /* include guard */