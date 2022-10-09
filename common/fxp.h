/**
 * ======================================
 * common/fxp.h: fixed-point arithmetics.
 * ======================================
 * NOTHING IS FINAL IN THIS FILE
 */

#ifndef __GOOF_FIXED_POINT_H
#define __GOOF_FIXED_POINT_H "common/fxp.h"

#include "common_defs.h"
#include "assert.h"

/**
 * Fixed-size fixed-point numbers.
 * A fixed-point number shall be interpreted as its undelying integer type
 * divided by 2^precision.
 *
 * Naming convention: `__<signedness>f<width>_<precision>_t`.
 * 
 * Ideally all valid (w,p) combinations should be supported, but then
 * implementing the associated functions becomes REALLY difficult. I am open to
 * suggestions regarding this, and other fixed-point-related stuff. For now I
 * plan to implement 16 types.
 */
#include <fenv.h>

#define __FXPENV_ROUND_TOZERO       ((int)0)
#define __FXPENV_ROUND_UP           ((int)1)
#define __FXPENV_ROUND_DOWN         ((int)-1)
#define __FXPENV_ROUND_TONEAREST    ((int)2)

/**
 * Set the thread-local rounding mode for fixed-point operations.
 * Accepted values are:
 *      __FXPENV_ROUND_TOZERO    - always round towards 0;
 *      __FXPENV_ROUND_UP        - always round up;
 *      __FXPENV_ROUND_DOWN      - always round down;
 *      __FXPENV_ROUND_TONEAREST - round to the nearest representable value,
 *                              if two values are equally far away, there is
 *                              no guarantee which one will be chosen;
 * The default rounding mode is __FXPENV_ROUND_TOZERO.
 *                                      
 */
extern void __fxpenv_set_rounding_mode(const int mode);

/** Get the thread-local rounding mode for fixed-point operations. */
extern int __fxpenv_get_rounding_mode();

#define __DEF_SFXP_T(wdt, ip, fp)               \
    typedef union {                             \
        __sint ## wdt ## _t r;                  \
        struct {                                \
            _Bool s : 1;                        \
            __uintmax_t i : ip;                 \
            __uintmax_t f : fp;                 \
        };                                      \
    } __sfxp ## wdt ## _ ## fp ## _t;           \
    assert(sizeof(__sfxp ## wdt ## _ ## fp ## _t) == wdt / 8);

#define __DEF_UFXP_T(wdt, ip, fp)               \
    typedef union {                             \
        __uint ## wdt ## _t r;                  \
        struct {                                \
            __uintmax_t i : ip;                 \
            __uintmax_t f : fp;                 \
        };                                      \
    } __ufxp ## wdt ## _ ## fp ## _t;           \
    assert(sizeof(__ufxp ## wdt ## _ ## fp ## _t) == wdt / 8);

/* High precision, low range */
__DEF_SFXP_T(16, 1, 14)
__DEF_UFXP_T(16, 1, 15)
__DEF_SFXP_T(32, 1, 30)
__DEF_UFXP_T(32, 1, 31)
__DEF_SFXP_T(64, 1, 62)
__DEF_UFXP_T(64, 1, 63)

/* medium precision, medium range */
__DEF_SFXP_T(16, 7, 8)
__DEF_UFXP_T(16, 8, 8)
__DEF_SFXP_T(32, 15, 16)
__DEF_UFXP_T(32, 16, 16)
__DEF_SFXP_T(64, 31, 32)
__DEF_UFXP_T(64, 32, 32)

/* low precision, high range */
__DEF_SFXP_T(32, 23, 8)
__DEF_UFXP_T(32, 24, 8)
__DEF_SFXP_T(64, 47, 16)
__DEF_UFXP_T(64, 48, 16)

#define add(a, b) ((typeof(a)){.r=(a.r + b.r)})
#define sub(a, b) ((typeof(a)){.r=(a.r - b.r)})

#endif /* include guard */