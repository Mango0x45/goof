#include "mem.h"

void mem_rep_copy(mem_s src, size_t stride, mem_s dst) {
	// TODO: Ensure that src.len <= stride or the stride is zero.
	if (stride == 0) {
		if (src.len > dst.len) return;
		mem_copy(src, (mem_s) { .ptr = dst.ptr, .len = src.len });
	} else for (size_t off = 0; off + src.len <= dst.len; off += stride)
		mem_copy(src, (mem_s) { .ptr = dst.ptr + off, .len = src.len });
}
