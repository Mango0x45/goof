#include "mem.h"

#include <string.h>

bool mem_iseq(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return false;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len) == 0;
}

bool mem_isne(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return true;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len) != 0;
}

bool mem_islt(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return lhs.len < rhs.len;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len) < 0;
}

bool mem_isle(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return lhs.len < rhs.len;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len) <= 0;
}

bool mem_isgt(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return lhs.len > rhs.len;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len) > 0;
}

bool mem_isge(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return lhs.len > rhs.len;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len) >= 0;
}
