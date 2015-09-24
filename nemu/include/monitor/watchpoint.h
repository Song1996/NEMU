#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"

typedef struct watchpoint {
	int NO;
	struct watchpoint *next;
	char* Expr;
	/* TODO: Add more members if necessary */


} WP;
WP* new_wp();
void free_up(WP *wp);

#endif
