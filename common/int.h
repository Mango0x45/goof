/**
 * ===============================================
 * common/int.h: pretty integer types definitions.
 * ===============================================
 */

#ifndef __INT_H
#define __INT_H "common/int.h"

#include "internal_types.h"

/**
 * Pretty fixed-width integer type names. (e.g.: i32)
 */
#define __PRETTY_INT_NAME(width) \
    typedef __sint ## width ## _t i ## width; \
    typedef __uint ## width ## _t u ## width;
__PRETTY_INT_NAME(8)
__PRETTY_INT_NAME(16)
__PRETTY_INT_NAME(32)
__PRETTY_INT_NAME(64)
__PRETTY_INT_NAME(max)
__PRETTY_INT_NAME(ptr)
#undef __PRETTY_INT_NAME

/** An 8-bit byte, as they all should be. */
typedef __uchar_t byte;
/** Unsigned integral type the size of a machine word. */
typedef __uintword_t word;

#endif /* include guard */