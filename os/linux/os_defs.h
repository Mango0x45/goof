/**
 * ===============================================
 * os/linux/os_defs.h: Linux-specific definitions.
 * ===============================================
 */

#ifndef __OS_DEFS_H
#define __OS_DEFS_H "os/linux/os_defs.h"

#ifndef __linux__
#error "Wrong os_defs.h file! This is os/linux."
#endif

#define __OS_TYPE LINUX
#define __OS LINUX_GENERIC

#endif