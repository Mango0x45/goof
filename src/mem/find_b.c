#include "mem.h"

#include <string.h>

unsigned char *mem_findp_b(unsigned char b, mem_s space) {
	return memchr(space.ptr, b, space.len);
}

size_t mem_findo_b(unsigned char b, mem_s space) {
	unsigned char *p = mem_findp_b(b, space);
	return p == NULL ? space.len : (size_t) (p - space.ptr);
}
