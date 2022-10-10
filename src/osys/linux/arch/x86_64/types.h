/**
 * =================================================
 * linux/x86_64/types.h: Core types for x86_64 Linux
 * =================================================
 * 
 * TODO: Determine how much of this is specific to x86_64 Linux, and how much is
 * general enough to be located elsewhere.
 */

#ifndef GOOF_OSYS_LINUX_ARCH_X86_64_TYPES_H
#define GOOF_OSYS_LINUX_ARCH_X86_64_TYPES_H

typedef unsigned char byte;

typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned int       u32;
typedef unsigned long int  u64;
typedef unsigned long int  unat;
typedef unsigned long int  ulen;
typedef unsigned long int  uptr;

typedef   signed char      i8;
typedef   signed short int i16;
typedef   signed int       i32;
typedef   signed long int  i64;
typedef   signed long int  inat;
typedef   signed long int  ilen;
typedef   signed long int  iptr;

#endif // #ifndef GOOF_OSYS_LINUX_ARCH_X86_64_TYPES_H
