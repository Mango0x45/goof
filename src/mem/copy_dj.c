#include "assert.h"
#include "mem.h"

#include <string.h>

const char *err = "mem_cpy_dj: src and dst have unequal lengths %zu and %zu";

void mem_copy_dj(mem_s src, mem_s dst) {
	assert(src.len == dst.len, err, src.len, dst.len);
	memcpy(dst.ptr, src.ptr, src.len);
}
