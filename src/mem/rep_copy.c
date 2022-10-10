#include "assert.h"
#include "mem.h"

const char *err =
	"mem_rep_copy: src.len of length %zu is greater than non-zero stride (%zu)";

void mem_rep_copy(mem_s src, ulen stride, mem_s dst) {
	assert(src.len <= stride || stride == 0, err, src.len, stride);

	if (stride == 0) {
		if (src.len > dst.len) return;
		mem_copy(src, (mem_s) { .ptr = dst.ptr, .len = src.len });
	} else for (ulen off = 0; off + src.len <= dst.len; off += stride)
		mem_copy(src, (mem_s) { .ptr = dst.ptr + off, .len = src.len });
}
