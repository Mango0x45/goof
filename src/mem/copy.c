#include "mem.h"

#include <string.h>

void mem_copy(mem_s src, mem_s dst) {
	// TODO: Ensure that src and dst have the same length.
	memcpy(dst.ptr, src.ptr, src.len);
}
