#include "mem.h"

bool mem_iseq(mem_s lhs, mem_s rhs) {
	return mem_coll(lhs, rhs) == 0;
}

bool mem_isne(mem_s lhs, mem_s rhs) {
	return mem_coll(lhs, rhs) != 0;
}

bool mem_islt(mem_s lhs, mem_s rhs) {
	return mem_coll(lhs, rhs) < 0;
}

bool mem_isle(mem_s lhs, mem_s rhs) {
	return mem_coll(lhs, rhs) <= 0;
}

bool mem_isgt(mem_s lhs, mem_s rhs) {
	return mem_coll(lhs, rhs) > 0;
}

bool mem_isge(mem_s lhs, mem_s rhs) {
	return mem_coll(lhs, rhs) >= 0;
}
