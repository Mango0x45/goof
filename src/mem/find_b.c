#include "mem.h"

#include <string.h>

byte *mem_findp_b(byte b, mem_s space) {
	return memchr(space.ptr, b, space.len);
}

ulen mem_findo_b(byte b, mem_s space) {
	byte *p = mem_findp_b(b, space);
	return p == NULL ? space.len : (ulen) (p - space.ptr);
}
