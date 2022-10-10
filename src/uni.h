/**
 * =========================
 * goof/uni: Unicode strings
 * =========================
 */

#ifndef GOOF_UNI_H
#define GOOF_UNI_H

#include <mem.h>
#include <types.h>

/**
 * A Unicode codepoint.
 */
typedef s32 uni_c;

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
		byte *ptr;

		/**
		 * The number of bytes in the data.
		 */
		ulen len;
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
static inline void uni_copy(uni_s src, uni_s dst) {
	mem_copy(src.m, dst.m);
}

/**
 * Copy data between two disjoint strings.
 * 
 * This is functionally equivalent to uni_copy(), but takes advantage of the
 * fact that the two strings are known to be disjoint (i.e. do not overlap in
 * memory at all).  It is the caller's responsibility to ensure this invarint
 * upholds -- if they cannot, uni_copy() should be used.
 */
static inline void uni_copy_dj(uni_s src, uni_s dst) {
	mem_copy_dj(src.m, dst.m);
}

/**
 * An ordering can be defined for Unicode strings based on byte values.  This is
 * the fastest but most semantically incorrect ordering -- Unicode strings that
 * are canonically equivalent may be arbitrarily different bytewise.  
 */

/**
 * Compare two strings for bytewise equality.
 */
static inline bool uni_iseq_bytewise(uni_s lhs, uni_s rhs) {
	return mem_iseq(lhs.m, rhs.m);
}

/**
 * Compare two strings for bytewise inequality.
 */
static inline bool uni_isne_bytewise(uni_s lhs, uni_s rhs) {
	return mem_isne(lhs.m, rhs.m);
}

/**
 * Compare two strings for bytewise lesser-than.
 */
static inline bool uni_islt_bytewise(uni_s lhs, uni_s rhs) {
	return mem_islt(lhs.m, rhs.m);
}

/**
 * Compare two strings for bytewise lesser-than or equal-to.
 */
static inline bool uni_isle_bytewise(uni_s lhs, uni_s rhs) {
	return mem_isle(lhs.m, rhs.m);
}

/**
 * Compare two strings for bytewise greater-than.
 */
static inline bool uni_isgt_bytewise(uni_s lhs, uni_s rhs) {
	return mem_isgt(lhs.m, rhs.m);
}

/**
 * Compare two strings for bytewise greater-than or equal-to.
 */
static inline bool uni_isge_bytewise(uni_s lhs, uni_s rhs) {
	return mem_isge(lhs.m, rhs.m);
}

/**
 * Collate two strings bytewise.
 */
static inline int uni_coll_bytewise(uni_s lhs, uni_s rhs) {
	return mem_coll(lhs.m, rhs.m);
}

#endif // #ifndef GOOF_UNI_H
