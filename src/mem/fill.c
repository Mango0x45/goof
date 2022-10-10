#include "mem.h"

void mem_fill(byte src, mem_s dst) {
	for (ulen i = 0; i < dst.len; i++)
		dst.ptr[i] = src;
}
