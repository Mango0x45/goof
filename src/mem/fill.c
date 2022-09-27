#include "mem.h"

void mem_fill(unsigned char src, mem_s dst) {
	for (int i = 0; i < dst.len; i++)
		dst.ptr[i] = src;
}
