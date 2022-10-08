#ifndef __GOOF_ASSERT_H
#define __GOOF_ASSERT_H

// TODO: Remove this once Raul's branch adding booleans is merged
#include <stdbool.h>

/**
 * Assert that the predicate `p` is true.  If it is not then abort execution and
 * print the diagnostic message `fmt` to standard error.  If `fmt` is NULL then
 * no error is printed.  You can also use printf() style formatting for more
 * advanced diagnostic output.
 */
void assert(bool p, const char *fmt, ...);

#endif // #ifndef __GOOF_ASSERT_H
