#ifndef _LINUX_TIMERQUEUE_H
#define _LINUX_TIMERQUEUE_H
#ifdef __KERNEL__
#include <linux/rbtree.h>
#endif
#include <linux/ktime.h>


struct timerqueue_node {
#ifdef __KERNEL__
	struct rb_node node;
#endif
	ktime_t expires;
};

struct timerqueue_head {
#ifdef __KERNEL__
	struct rb_root head;
#endif
	struct timerqueue_node *next;
};


extern void timerqueue_add(struct timerqueue_head *head,
				struct timerqueue_node *node);
extern void timerqueue_del(struct timerqueue_head *head,
				struct timerqueue_node *node);
extern struct timerqueue_node *timerqueue_iterate_next(
						struct timerqueue_node *node);

/**
 * timerqueue_getnext - Returns the timer with the earliest expiration time
 *
 * @head: head of timerqueue
 *
 * Returns a pointer to the timer node that has the
 * earliest expiration time.
 */
static inline
struct timerqueue_node *timerqueue_getnext(struct timerqueue_head *head)
{
	return head->next;
}

static inline void timerqueue_init(struct timerqueue_node *node)
{
	RB_CLEAR_NODE(&node->node);
}

static inline void timerqueue_init_head(struct timerqueue_head *head)
{
	head->head = RB_ROOT;
	head->next = NULL;
}
#endif /* _LINUX_TIMERQUEUE_H */
