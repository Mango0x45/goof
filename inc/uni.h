/**
 * =========================
 * goof/uni: Unicode strings
 * =========================
 */

#ifndef GOOF_UNI_H
#define GOOF_UNI_H

#include "mem.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * A Unicode codepoint.
 */
typedef uint32_t uni_c;

/**
 * A Unicode string.
 * 
 * This is a slice of memory which is guaranteed to contain valid UTF-8 data.
 */
typedef union {
	struct {
		/**
		 * A pointer to the UTF-8 data.
		 */
		unsigned char* ptr;

		/**
		 * The number of bytes in the data.
		 */
		size_t len;
	};

	/**
	 * The corresponding memory slice.
	 */
	mem_s m;
} uni_s;

/**
 * Overwrite one string with the content of another.
 * 
 * Note that this function can be used even if the two strings overlap -- it
 * will account for the overlap and ensure that data is copied correctly.
 */
void uni_copy(uni_s src, uni_s dst);

/**
 * Copy data between two disjoint strings.
 * 
 * This is functionally equivalent to uni_copy(), but takes advantage of the
 * fact that the two strings are known to be disjoint (i.e. do not overlap in
 * memory at all).  It is the caller's responsibility to ensure this invarint
 * upholds -- if they cannot, uni_copy() should be used.
 */
void uni_copy_dj(uni_s src, uni_s dst);

/**
 * Compare two strings for bytewise equality.
 * 
 * This function returns true if and only if the two strings contain exactly the
 * same byte values, in the same order.
 */
bool uni_iseq_bytewise(uni_s lhs, uni_s rhs);

/**
 * Compare two strings for bytewise inequality.
 * 
 * This function returns false if and only if the two strings contain exactly
 * the same byte values, in the same order.
 */
bool uni_isne_bytewise(uni_s lhs, uni_s rhs);

#endif // #ifndef GOOF_UNI_H
