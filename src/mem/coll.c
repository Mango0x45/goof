#include "mem.h"

cmp mem_coll(mem_s lhs, mem_s rhs) {
	ulen min = (lhs.len < rhs.len) ? lhs.len : rhs.len;
	byte l, r;
	for (ulen i = 0; i < min; i++)
		if ((l = lhs.ptr[i]) != (r = rhs.ptr[i]))
			return (l < r) ? CMP_LT : CMP_GT;
	return (lhs.len < rhs.len) ? CMP_LT : (lhs.len > rhs.len) ? CMP_GT : CMP_EQ;
}
