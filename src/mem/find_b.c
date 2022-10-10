#include "mem.h"

byte *mem_findp_b(byte b, mem_s space) {
	for (ulen i = 0; i < space.len; i++)
		if (space.ptr[i] == b)
			return &space.ptr[i];
	return NULL;
}

ulen mem_findo_b(byte b, mem_s space) {
	byte *p = mem_findp_b(b, space);
	return p == NULL ? space.len : (ulen) (p - space.ptr);
}
