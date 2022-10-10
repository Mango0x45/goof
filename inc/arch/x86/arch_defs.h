/**
 * ==================================================
 * arch/x86/arch_defs.h: general architecture macros.
 * ==================================================
 * 
 * THIS HEADER DOES NOT HAVE AN INCLUDE GUARD!
 */

#ifndef __ARCH_DEFS_H
#define __ARCH_DEFS_H "arch/x86/arch_defs.h

#if !defined __i386__ && !defined _M_IX86
#error "Using wrong arch_defs.h file! This is x86."
#endif

#define __ARCH x86
#define __ARCH_BITS 32
#define __WORDSIZE __ARCH_BITS

#endif /* include guard */