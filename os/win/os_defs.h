/**
 * ===============================================
 * os/win/os_defs.h: Windows-specific definitions.
 * ===============================================
 */

#ifndef __OS_DEFS_H
#define __OS_DEFS_H "os/linux/os_defs.h"

#ifndef _WIN64
#error "Wrong os_defs.h file! This is os/win."
#endif

#define __OS_TYPE WIN
#define __OS WIN_GENERIC

#endif