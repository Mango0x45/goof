/**
 * ===============================================
 * common/common_defs.h: general goof definitions.
 * ===============================================
 */

#ifndef __COMMON_DEFS_H
#define __COMMON_DEFS_H "common/common_defs.h"

#include "comp_defs.h"
#include "arch_defs.h"
#include "os_defs.h"
#include "internal_types.h"

#define NULL ((void*)0)

#if __STDC_VERSION__ < 202000L /* C23 will define these as keywords */
#define alignas(e) _Alignas(e)
#define alignof(e) _Alignof(e)
#define bool _Bool
#endif

#define complex _Complex
#define imaginary _Imaginary

typedef __size_t        size_t;
typedef __ptrdiff_t     ptrdiff_t;
typedef __nullptr_t     nullptr_t;

#endif /* include guard */