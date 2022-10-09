/**
 * =================================================
 * os/win/x86_64/os_defs.h: OS-specific definitions.
 * =================================================
 */

#ifndef __OS_DEFS_H
#define __OS_DEFS_H "os/win/x86_64/os_defs.h"

#ifndef _WIN64
#error "Wrong os_defs.h file! Currently using win/x86_64."
#endif

#define __OS_TYPE WIN
#define __OS WIN64

#endif /* include guard */
