#include "mem.h"

#include <string.h>

int mem_coll(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return (lhs.len < rhs.len) ? -1 : 1;
	return memcmp(lhs.ptr, rhs.ptr, lhs.len);
}
