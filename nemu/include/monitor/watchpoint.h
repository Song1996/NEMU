#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"

typedef struct watchpoint {
	int NO;
	struct watchpoint *next;
	char Expr[100];
	int Value;
	/* TODO: Add more members if necessary */


} WP;
WP* new_wp();
void free_wp(WP *wp);
WP* WP_returnhead();

#endif
