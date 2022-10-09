/**
 * =============================================
 * comp/clang/comp_defs.h: Clang-specific stuff.
 * =============================================
 */

#ifndef __COMP_DEFS_H
#define __COMP_DEFS_H "comp/clang/comp_defs.h"

#ifndef __clang__
#error "Wrong comp_defs.h file! Currently using clang."
#endif

#define offsetof(t, d) __builtin_offsetof(t, d)

#if __STDC_VERSION__ < 202000L
#define typeof(x) __typeof__(x)
#endif

#endif /* include guard */