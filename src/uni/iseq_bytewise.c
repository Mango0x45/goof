#include "uni.h"

#include "mem.h"

bool uni_iseq_bytewise(uni_s lhs, uni_s rhs) {
	return mem_iseq(lhs.m, rhs.m);
}
