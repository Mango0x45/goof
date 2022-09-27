/**
 * =============================
 * goof/mem: manipulating memory
 * =============================
 */

#ifndef GOOF_MEM_H
#define GOOF_MEM_H

#include <stdbool.h>
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
 * Note that this function can be used even if the two memory slices overlap --
 * it will account for the overlap and ensure that data is copied correctly.
 */
void mem_copy(mem_s src, mem_s dst);

/**
 * Copy bytes between two disjoint slices of memory.
 * 
 * This is functionally equivalent to mem_copy(), but takes advantage of the
 * fact that the two slices of memory are known to be disjoint (i.e. do not
 * overlap at all).  It is the caller's responsibility to ensure this invarint
 * upholds -- if it is not guaranteed to hold, mem_copy() should be used
 * instead.
 */
void mem_copy_dj(mem_s src, mem_s dst);

/**
 * Fill a slice of memory with a constant byte.
 *
 * This sets every byte in the memory slice dst with the byte specified by src.
 * In other words, after this function is invoked dst will look like:
 * 	{ src, src, ..., src }
 */
void mem_fill(unsigned char src, mem_s dst);

/**
 * Zero a slice of memory.
 *
 * This is functionally equivalent to mem_fill(0, dst).
 */
void mem_zero(mem_s dst);

/**
 * Compare two slices of memory for equality.
 * 
 * This function returns true if and only if the two slices contain exactly the
 * same byte values, in the same order.  It is the opposite of mem_isne().
 */
bool mem_iseq(mem_s lhs, mem_s rhs);

/**
 * Compare two slices of memory for inequality.
 * 
 * This function returns false if and only if the two slices contain exactly the
 * same byte values, in the same order.  It is the opposite of mem_iseq().
 */
bool mem_isne(mem_s lhs, mem_s rhs);

/**
 * Find the address of a subslice within a slice.
 *
 * The function searches for the first occurance of the slice s in the memory
 * slice space.  If the slice is found, the address of it's beginning is
 * returned.  If no slice is found then NULL is returned.
 */
unsigned char *mem_findp(mem_s s, mem_s space);

/**
 * Find the offset of a subslice within a slice.
 *
 * This is functionally equivalent to mem_findp() except it returns the offset
 * (index) of the found slice instead of a pointer to it.  If the slice is not
 * found within the search space, the length of the space is returned.
 */
size_t mem_findo(mem_s s, mem_s space);

/**
 * Find the address of a byte within a slice.
 *
 * The function searches for the first occurance of the byte b in the memory
 * slice space.  If the byte is found, it's address is returned.  If no byte is
 * found then NULL is returned.
 */
unsigned char *mem_findp_b(unsigned char b, mem_s space);

/**
 * Find the offset of a byte within a slice.
 *
 * This is functionally equivalent to mem_findp_b() except it returns the offset
 * (index) of the found byte instead of a pointer to it.  If the byte is not
 * found within the search space, the length of the space is returned.
 */
size_t mem_findo_b(unsigned char b, mem_s space);

#endif // #ifndef GOOF_MEM_H
