#include "cpu/exec/template-start.h"

#define instr jmp

static void do_execute(){
	int src=op_src->val;
	cpu.eip+=src;
	print_asm_template1();
}

make_instr_helper(si)
make_instr_helper(rm)

#include "cpu/exec/template-end.h"
