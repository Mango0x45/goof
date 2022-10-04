/**
 * =============================
 * goof/mem: manipulating memory
 * =============================
 */

#ifndef GOOF_MEM_H
#define GOOF_MEM_H

#include "types.h"

#include <stdbool.h>
#include <stddef.h>

/**
 * A slice of memory.
 */
typedef struct {
	/**
	 * A pointer to the memory region.
	 */
	byte *ptr;

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
void mem_fill(byte src, mem_s dst);

/**
 * Zero a slice of memory.
 *
 * This is functionally equivalent to mem_fill(0, dst).
 */
void mem_zero(mem_s dst);

/**
 * Repeatedly copy a slice of memory into another.
 * 
 * At byte offsets that are integer multiples of the given "stride", the source
 * memory slice will be copied into the destination.  The source slice must have
 * a length smaller than or equal to the stride.  At the end of the destination
 * slice, if there is not enough space to copy the entire source slice for the
 * last stride, it will simply not be copied.
 * 
 * A stride of zero is equivalent to copying the source slice to the beginning
 * of the destination slice (if there is enough space to do so).
 */
void mem_rep_copy(mem_s src, size_t stride, mem_s dst);

/**
 * A strict ordering can be defined over memory slices.  If one slice is smaller
 * in length than another slice, then it is conceptually strictly less than the
 * other.  If two slices have the same length, but at the first index where they
 * differ the first slice has a smaller byte value than the second, then it is
 * conceptually strictly less than the second.  If two slices are identical in
 * length and byte values, then they are conceptually equal.
 */

/**
 * Compare two slices of memory for equality.
 */
bool mem_iseq(mem_s lhs, mem_s rhs);

/**
 * Compare two slices of memory for inequality.
 */
bool mem_isne(mem_s lhs, mem_s rhs);

/**
 * Compare two slices of memory for lesser-than.
 */
bool mem_islt(mem_s lhs, mem_s rhs);

/**
 * Compare two slices of memory for lesser-than or equal-to.
 */
bool mem_isle(mem_s lhs, mem_s rhs);

/**
 * Compare two slices of memory for greater-than.
 */
bool mem_isgt(mem_s lhs, mem_s rhs);

/**
 * Compare two slices of memory for greater-than or equal-to.
 */
bool mem_isge(mem_s lhs, mem_s rhs);

/**
 * Collate two slices of memory.
 * 
 * An integer is returned, whose sign determines the ordering between the two
 * slices.  If the integer is less than zero, then the left slice is less than
 * the right slice.  If the integer is greater than zero, then the left slice is
 * greater than the right slice.  If the integer is equal to zero, then the left
 * slice is equal to the right slice.
 */
int mem_coll(mem_s lhs, mem_s rhs);

/**
 * Find the address of a subslice within a slice.
 *
 * The function searches for the first occurance of the slice 's' in the memory
 * slice 'space'.  If the slice is found, the address of its beginning is
 * returned.  If no slice is found then NULL is returned.
 */
byte *mem_findp(mem_s s, mem_s space);

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
 * The function searches for the first occurance of the byte 'b' in the memory
 * slice 'space'.  If the byte is found, its address is returned.  If no byte is
 * found then NULL is returned.
 */
byte *mem_findp_b(byte b, mem_s space);

/**
 * Find the offset of a byte within a slice.
 *
 * This is functionally equivalent to mem_findp_b() except it returns the offset
 * (index) of the found byte instead of a pointer to it.  If the byte is not
 * found within the search space, the length of the space is returned.
 */
size_t mem_findo_b(byte b, mem_s space);

#endif // #ifndef GOOF_MEM_H
