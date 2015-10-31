#include "cpu/exec/template-start.h"

#define instr stos

make_helper(concat(stos_,SUFFIX))
{
	MEM_W(cpu.edi,cpu.eax);
	if(cpu.DF==0)cpu.edi+=DATA_BYTE;
	else cpu.edi-=DATA_BYTE;
	print_asm("stos");
	return 1;
}

#include "cpu/exec/template-end.h"
