#include "cpu/exec/template-start.h"

#define instr ret

make_helper(concat(ret_,SUFFIX))
{
	cpu.eip=MEM_R(cpu.esp);
	cpu.esp+=DATA_BYTE;
	print_asm("ret\n");
	cpu.eip--;
	return 1;
}


#include "cpu/exec/template-end.h"
