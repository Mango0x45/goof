#include "mem.h"

int mem_coll(mem_s lhs, mem_s rhs) {
	if (lhs.len != rhs.len) return (lhs.len < rhs.len) ? -1 : 1;
	byte l, r;
	for (ulen i = 0; i < lhs.len; i++)
		if ((l = lhs.ptr[i]) != (r = rhs.ptr[i]))
			return (l < r) ? -1 : (l > r) ? 1 : 0;
	return 0;
}
