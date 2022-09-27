#include "mem.h"

#include <string.h>

void mem_fill(unsigned char src, mem_s dst) {
	memset(dst.ptr, src, dst.len);
}
