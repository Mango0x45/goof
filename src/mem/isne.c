#include "mem.h"

#include <string.h>

bool mem_isne(mem_s src, mem_s dst) {
	if (src.len != dst.len) return true;
	return memcmp(src.ptr, dst.ptr, src.len) != 0;
}