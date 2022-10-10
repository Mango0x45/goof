#include "assert.h"

void abort(void) {
	asm volatile ("syscall" :: "a" (60), "D" (1));
	__builtin_unreachable();
}
