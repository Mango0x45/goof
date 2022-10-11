/**
 * =========================
 * goof/uni: Unicode strings
 * =========================
 */

#ifndef GOOF_UNI_H
#define GOOF_UNI_H

#include <assert.h>
#include <mem.h>
#include <types.h>

/**
 * A Unicode codepoint.
 */
typedef u32 uni_c;

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
 * Whether the given position in a string is a code-point boundary.
 */
static inline bool uni_is_cpb(uni_s str, ulen pos) {
	if (pos >= str.len) return false;
	return str.ptr[pos] < 128;
}

/**
 * Construct a string from the given literal.
 * 
 * TODO: Verify that the input is valid Unicode.
 */
#define UNI(_str) ((uni_s) { .ptr = (byte *) (_str), .len = sizeof(_str) - 1 })

static inline uni_s __uni_gets(uni_s str, ulen beg, ulen end, ulen len) {
	assert(end == 0 || len == 0, NULL);
	if (len) {
		assert(uni_is_cpb(str, beg) && uni_is_cpb(str, beg + len), NULL);
		return (uni_s) { .ptr = str.ptr + beg, .len = len };
	} else {
		assert(uni_is_cpb(str, beg) && uni_is_cpb(str, end), NULL);
		return (uni_s) { .ptr = str.ptr + beg, .len = end - beg };
	}
}

/**
 * Slice the given string.
 * 
 * ```
 * uni_s str;
 * uni_gets(str, 4, 6); // &str[4 .. 6]
 * uni_gets(str, 4, .end = 6); // &str[4 .. 6]
 * uni_gets(str, 4, .len = 2); // &str[4 .. 6]
 * ```
 */
#define uni_gets(_str, ...) ({ \
	struct { ulen beg, end, len; } __sel = { __VA_ARGS__ }; \
	__uni_gets(_str, __sel.beg, __sel.end, __sel.len); })

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
