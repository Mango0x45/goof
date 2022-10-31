#include "mem.h"

#include <cmp.h>

bool mem_iseq(mem_s lhs, mem_s rhs) {
	return cmp_eq(mem_coll(lhs, rhs));
}

bool mem_isne(mem_s lhs, mem_s rhs) {
	return cmp_ne(mem_coll(lhs, rhs));
}

bool mem_islt(mem_s lhs, mem_s rhs) {
	return cmp_lt(mem_coll(lhs, rhs));
}

bool mem_isle(mem_s lhs, mem_s rhs) {
	return cmp_le(mem_coll(lhs, rhs));
}

bool mem_isgt(mem_s lhs, mem_s rhs) {
	return cmp_gt(mem_coll(lhs, rhs));
}

bool mem_isge(mem_s lhs, mem_s rhs) {
	return cmp_ge(mem_coll(lhs, rhs));
}
