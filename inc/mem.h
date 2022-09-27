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
 * 
 * Note that this function can be used even if the two memory slices overlap -- it will
 * account for the overlap and ensure that data is copied correctly.
 */
void mem_copy(mem_s src, mem_s dst);

/**
 * Copy bytes between two disjoint slices of memory.
 * 
 * This is functionally equivalent to mem_copy(), but takes advantage of the fact that the
 * two slices of memory are known to be disjoint (i.e. do not overlap at all).  It is the
 * caller's responsibility to ensure this invarint upholds -- if it is not guaranteed to
 * hold, mem_copy() should be used instead.
 */
void mem_copy_dj(mem_s src, mem_s dst);

#endif // #ifndef GOOF_MEM_H
