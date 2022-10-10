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

#include "osys/types.h"

#define NULL  ((void*) 0)
#define bool  _Bool
#define true  ((_Bool) 1)
#define false ((_Bool) 0)

#endif // #ifndef GOOF_TYPES_H
