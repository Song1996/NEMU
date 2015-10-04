#include "cpu/exec/template-start.h"

#define instr je

static void do_execute(){
	int src=op_src->val;
	if(cpu.ZF)
		cpu.eip += src;
	print_asm_template1();
}

make_instr_helper(i)

#include "cpu/exec/template-end.h"
