#include "cpu/exec/template-start.h"


make_helper(concat(ret_,SUFFIX))
{
	cpu.eip=MEM_R(cpu.esp);
	cpu.esp+=DATA_BYTE;
	print_asm_template1();
	return 1;
}


#include "cpu/exec/template-end.h"
