/**
 * =============================
 * goof/mem: manipulating memory
 * =============================
 */

#ifndef GOOF_MEM_H
#define GOOF_MEM_H

#include <stddef.h>

/**
 * A slice of memory.
 */
typedef struct {
	/**
	 * A pointer to the memory region.
	 */
	unsigned char* ptr;

	/**
	 * The number of bytes.
	 */
	size_t len;
} mem_s;

/**
 * Copy bytes from one slice of memory to another.
 */
void mem_copy(mem_s src, mem_s dst);

#endif // #ifndef GOOF_MEM_H
