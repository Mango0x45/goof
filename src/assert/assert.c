#include "assert.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void
assert(bool p, const char *fmt, ...)
{
	if (p)
		return;
	if (fmt) {
		va_list ap;
		va_start(ap, fmt);
		// TODO: We want to prefix the output with the program name, which is
		// standard behavior for most software.  To do this we need to be able
		// to get the program name though, which requires first writing a custom
		// entry function (__goof_start() or something).
		fprintf(stderr, "assertion failed: ");
		vfprintf(stderr, fmt, ap);
		va_end(ap);
		fputc('\n', stderr);
	}
	abort();
}
