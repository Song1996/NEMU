#include "monitor/watchpoint.h"
#include "monitor/expr.h"

#define NR_WP 32

static WP wp_list[NR_WP];
static WP *head, *free_;

void init_wp_list() {
	int i;
	for(i = 0; i < NR_WP; i ++) {
		wp_list[i].NO = i;
		wp_list[i].next = &wp_list[i + 1];
	}
	wp_list[NR_WP - 1].next = NULL;

	head = NULL;
	free_ = wp_list;
}

/* TODO: Implement the functionality of watchpoint */
WP* WP_returnhead()
{
	return head;
}

WP* new_wp()
{
	WP* t=free_;
	free_=t->next;
	t->next=head;
	head=t;
	return t;
}	

void free_wp(WP *wp)
{
	WP* t=head;
	if(t==wp)
	{
		head=wp->next;
		wp->next=free_;
		free_=wp;
		return;
	}
	else
	{
		while(t->next!=wp)
		{
			t=t->next;
		}
		t->next=t->next->next;
		wp->next=free_;
		free_=wp;
		return;
	}	
		
}
