#include "mem.h"

byte *mem_findp(mem_s s, mem_s space) {
	for (ulen i = 0; i <= space.len - s.len; i++)
		if (mem_iseq(s, (mem_s) { .ptr = space.ptr + i, .len = s.len }))
			return &space.ptr[i];
	return NULL;
}

ulen mem_findo(mem_s s, mem_s space) {
	byte *p = mem_findp(s, space);
	return p == NULL ? space.len : (ulen) (p - space.ptr);
}
