/**
 * ===============================================
 * common/int.h: pretty integer types definitions.
 * ===============================================
 * 
 * If __INT_H_STD_STYLE_INTS is defined when this file is included,
 * STD-style integer names (e.g: int32_t) will also be defined along with the
 * Goof ones (e.g: i32). This feature was added for comaptibility reasons and
 * may be removed at a later date if it is no longer deemed necessary.
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

/**
 * This needs to be outside of the regular include guard, such that these
 * types can be defined by a later inclusion of the header.
 */
#if defined __INT_H_STD_STYLE_INTS && \
    !defined __INT_H_STD_STYLE_INTS_DONE
    #define __INT_H_STD_STYLE_INTS_DONE
    #define __STD_LIKE_INT_NAME(width) \
    typedef __sint ## width ## _t int ## width ## _t; \
    typedef __uint ## width ## _t uint ## width ## _t;
    __STD_LIKE_INT_NAME(8)
    __STD_LIKE_INT_NAME(16)
    __STD_LIKE_INT_NAME(32)
    __STD_LIKE_INT_NAME(64)
    __STD_LIKE_INT_NAME(max)
    __STD_LIKE_INT_NAME(ptr)
#endif