#ifndef __GOOF_ASSERT_H
#define __GOOF_ASSERT_H

#include "types.h"

/**
 * Assert that the predicate `p` is true.  If it is not then abort execution and
 * print the diagnostic message `fmt` to standard error.  If `fmt` is NULL then
 * no error is printed.  You can also use printf() style formatting for more
 * advanced diagnostic output.
 */
void assert(bool p, char const *fmt, ...);

#endif // #ifndef __GOOF_ASSERT_H
