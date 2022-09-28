#include "uni.h"

#include "mem.h"

bool uni_isne_bytewise(uni_s lhs, uni_s rhs) {
	return mem_isne(lhs.m, rhs.m);
}
