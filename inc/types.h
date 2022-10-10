/**
 * ===================
 * types.h: Core types
 * ===================
 * 
 * This module provides basic types used by virtually all code.  Note that there
 * are various platform-specific variants of this header that provide many of
 * the necessary definitions.
 */

#ifndef GOOF_TYPES_H
#define GOOF_TYPES_H

#define NULL ((void *) 0)

// C23 introduces `bool`, `true`, and `false` as keywords.
#if __STDC_VERSION__ < 202000
	// C99 introduces the _Bool type.
	#if __STDC_VERSION__ >= 199901
		#define true  ((_Bool) 1)
		#define false ((_Bool) 0)
	#else
		typedef enum {
			false = 0,
			true  = 1
		} _Bool;
	#endif

	typedef _Bool bool;
#endif

#endif // #ifndef GOOF_TYPES_H
