#include "mem.h"

#include <string.h>

void mem_fill(byte src, mem_s dst) {
	memset(dst.ptr, src, dst.len);
}
