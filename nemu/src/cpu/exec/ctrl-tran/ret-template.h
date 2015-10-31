#include "cpu/exec/template-start.h"

#define instr ret

make_helper(concat(ret_,SUFFIX))
{
	cpu.eip=MEM_R(cpu.esp);
	cpu.esp+=4;
	print_asm("ret\n");
	cpu.eip--;
	return 1;
}

/*
make_helper(ret_si)
{
	concat(decode_si_,w)(eip+1);
	int src=op_src->val;
	cpu.eip=MEM_R(cpu.esp);
	cpu.esp+=4;
	cpu.eip+=src;
	cpu.eip--;
	return 3;
}
*/
#include "cpu/exec/template-end.h"
