#ifndef __ASM_GENERIC_CURRENT_H
#define __ASM_GENERIC_CURRENT_H

#include <linux/thread_info.h>
#ifdef __KERNEL__
#define get_current() (current_thread_info()->task)
#define current get_current()
#endif
#endif /* __ASM_GENERIC_CURRENT_H */
