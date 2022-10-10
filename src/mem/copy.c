#include "assert.h"
#include "mem.h"

static char const err[] =
	"mem_cpy: src and dst have unequal lengths %zu and %zu";

void mem_copy(mem_s src, mem_s dst) {
	assert(src.len == dst.len, err, src.len, dst.len);
	if (src.ptr > dst.ptr) {
		for (ulen i = 0; i < src.len; i++)
			dst.ptr[i] = src.ptr[i];
	} else if (src.ptr < dst.ptr) {
		for (ulen i = 0; i < src.len; i++)
			dst.ptr[src.len - i - 1] = src.ptr[src.len - i - 1];
	}
}
