#include "assert.h"

/**
 * Abort the program immediately.
 */
void abort(void);

void assert(bool p, char const *fmt, ...) {
	if (p) return;
	(void) fmt; // TODO: format and print the given error message.
	abort();
}
