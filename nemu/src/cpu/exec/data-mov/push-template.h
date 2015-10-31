#include "cpu/exec/template-start.h"

#define instr push

static void do_execute(){
	uint32_t src = op_src->val;
	cpu.esp -= 4;
	swaddr_write(cpu.esp,4,src);
	print_asm_template1();
}

make_instr_helper(rm)
make_instr_helper(r)
make_instr_helper(i)

#include "cpu/exec/template-end.h"
