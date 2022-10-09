/**
 * =====================================================
 * arch/x86_64/arch_defs.h: general architecture macros.
 * =====================================================
 * 
 * THIS HEADER DOES NOT HAVE AN INCLUDE GUARD!
 */

#ifndef __ARCH_DEFS_H
#define __ARCH_DEFS_H "arch/x86_64/arch_defs.h

#if !defined __x86_64__ && !defined _M_AMD64
#error "Using wrong arch_defs.h file! Currently using x86_64."
#endif

#define __ARCH x86_64
#define __ARCH_BITS 64
#define __WORDSIZE __ARCH_BITS

#endif /* include guard */