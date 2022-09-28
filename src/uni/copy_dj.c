#include "uni.h"

#include "mem.h"

void uni_copy_dj(uni_s src, uni_s dst) {
	mem_copy_dj(src.m, dst.m);
}
