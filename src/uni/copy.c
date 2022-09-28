#include "uni.h"

#include "mem.h"

void uni_copy(uni_s src, uni_s dst) {
	mem_copy(src.m, dst.m);
}
