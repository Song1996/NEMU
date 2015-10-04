#include "cpu/exec/template-start.h"

#define instr push

static void do_execute(){
	swaddr_t addr = op_src->val;
	cpu.esp -= DATA_BYTE;
	MEM_W(cpu.esp,addr);
	print_asm_template2();
}

make_instr_helper(r)

#include "cpu/exec/template-end.h"
