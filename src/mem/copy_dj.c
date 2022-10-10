#include "assert.h"
#include "mem.h"

static char const err[] =
	"mem_cpy_dj: src and dst have unequal lengths %zu and %zu";

void mem_copy_dj(mem_s src, mem_s dst) {
	assert(src.len == dst.len, err, src.len, dst.len);
	byte const *restrict s = src.ptr;
	byte *restrict d = dst.ptr;
	for (ulen i = 0; i < src.len; i++)
		d[i] = s[i];
}
