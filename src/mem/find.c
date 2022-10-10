#define _GNU_SOURCE
#include "mem.h"

#include <string.h>

byte *mem_findp(mem_s s, mem_s space) {
	return memmem(space.ptr, space.len, s.ptr, s.len);
}

ulen mem_findo(mem_s s, mem_s space) {
	byte *p = mem_findp(s, space);
	return p == NULL ? space.len : (ulen) (p - space.ptr);
}
