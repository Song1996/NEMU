#include "cpu/exec/template-start.h"

#define instr pop

static void do_execute() {
	//swaddr_t  addr=op_src->val;
	OPERAND_W(op_src,MEM_R(cpu.esp));
	cpu.esp+=4;
	print_asm_template1();
}

make_instr_helper(rm)
make_instr_helper(r)

#include "cpu/exec/template-end.h"
