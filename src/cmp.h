/**
 * =====================
 * goof/cmp: comparisons 
 * =====================
 * 
 * This module defines useful types and functionality for comparing objects.
 * It is primarily for convenience; for a standard library module, it does not
 * solve particularly complex problems, but it does stand as convention for any
 * comparison-related code.
 * 
 * This module supports both total and partial orderings.  A total ordering is
 * like that over the integers: every integer is strictly less than, equal to,
 * or strictly greater than every other integer.  A partial ordering allows for
 * the concept of incomparability: for example, if a set is lesser than another
 * when all of its elements are in the other (but not vice-versa), two sets that
 * do not share any elements with each other cannot be compared: neither one is
 * less than or greater than the other, and they are not equal.
 * 
 * For partial ordering, note that not-comparable implies not-equal: it simply
 * means that the two objects are neither less than or greater than each other.
 * It is not possible to state that two objects are not-comparable in the sense
 * that it is unknown whether they are equal or not; at least, not with `cmp`.
 */

#ifndef GOOF_CMP_H
#define GOOF_CMP_H

#include <types.h>

/**
 * The result of a partial (or total) comparison.
 * 
 * This has the following values: CMP_LT, if the first object was less than the
 * second; CMP_EQ, if the objects are equal; CMP_GT, if the first object is more
 * than the second; and CMP_NA, if the objects cannot be compared.
 */
typedef enum cmp {
	CMP_NA,
	CMP_LT,
	CMP_EQ,
	CMP_GT,
} cmp;

/**
 * Test whether the result of a comparison was not-comparable.
 */
static inline bool cmp_na(cmp cmp) {
	return cmp == CMP_NA;
}

/**
 * Test whether the result of a comparison was less-than.
 */
static inline bool cmp_lt(cmp cmp) {
	return cmp == CMP_LT;
}

/**
 * Test whether the result of a comparison was less-than or equal-to.
 */
static inline bool cmp_le(cmp cmp) {
	return cmp == CMP_LT || cmp == CMP_EQ;
}

/**
 * Test whether the result of a comparison was equal-to.
 */
static inline bool cmp_eq(cmp cmp) {
	return cmp == CMP_EQ;
}

/**
 * Test whether the result of a comparison was not equal-to.
 */
static inline bool cmp_ne(cmp cmp) {
	return cmp != CMP_EQ;
}

/**
 * Test whether the result of a comparison was greater-than.
 */
static inline bool cmp_gt(cmp cmp) {
	return cmp == CMP_GT;
}

/**
 * Test whether the result of a comparison was greater-than or equal-to.
 */
static inline bool cmp_ge(cmp cmp) {
	return cmp == CMP_GT || cmp == CMP_EQ;
}

/**
 * Sequence two comparisons.
 *
 * This method can be used for comparing aggregate objects.  If an aggregate is
 * composed of two fields, and it uses a sequential (lexicographic) ordering,
 * then comparison upon such aggregates operates thusly: the first fields are
 * compared, and only if they are equal, the second fields are compared.
 * 
 * The first comparison result is inspected.  If it is equal-to, then the second
 * comparison result is returned.  Otherwise, the first is returned.  This is a
 * monoidic function: it is associative and has an identity element (CMP_EQ).
 * As such, it can be evaluated unambiguously upon sequences of any length, by
 * using it to combine an aggregated result with the next field result.
 * 
 * This is the standard comparison aggregation operator, used for structures,
 * arrays, vectors, etc.  Note that a not-comparable result can only occur if
 * one of the input results is not-comparable; thus it "preserves" totality of
 * the ordering.
 */
static inline cmp cmp_seq(cmp a, cmp b) {
	return cmp_eq(a) ? b : a;
}

/**
 * Parallelize two comparisons.
 *
 * This method can be used for comparing aggregate objects.  If an aggregate is
 * composed of two fields, and it uses a parallel ordering, then comparison upon
 * such aggregates operates thusly: both fields are compared between the objects
 * simultaneously.  If one object is less in both fields, then it is the lesser;
 * if one object is less in one field but greater in the other, the result is
 * not-comparable.  If one object is less in one field but equal in the other,
 * then it is counted less.
 *
 * The two comparison results are inspected.  If either is not-comparable, it is
 * returned; if both are the same, the shared result is returned; if one of the
 * results is equal-to, then the other is returned; otherwise not-comparable is
 * returned.  This is a monoidic function; it is associative and has an identity
 * element (CMP_EQ), but is also commutative.  As such, it can be evaluated
 * unambiguously upon sets of any size, by calling it upon its own result to add
 * in additional fields.
 *
 * This is a relatively rare comparison aggregation operator, but it is used in
 * situations where all fields are equally important, and partial ordering is
 * in use.  Note that a not-comparable result can occur even if the inputs are
 * not not-comparables; thus it must only be used with partial orderings.
 */
static inline cmp cmp_par(cmp a, cmp b) {
	if (a == b) return a;
	if (cmp_eq(a)) return b;
	if (cmp_eq(b)) return a;
	return CMP_NA;
}

#endif // #ifndef GOOF_CMP_H
