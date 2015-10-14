#include "cpu/exec/helper.h"
#include "cpu/decode/modrm.h"

make_helper(cwq)
{
	int t=reg_w(R_AX);
	if(t<0)
		cpu.edx=cpu.edx|0x0000ffff;
	else
		cpu.edx=cpu.edx&0xffff0000;
	print_asm("cwq");
	return 1;
}

make_helper(cdq)
{
	int t=cpu.eax;
	if(t<0)
		cpu.edx=cpu.edx|0xffffffff;
	else
		cpu.edx=cpu.edx&0x00000000;
	print_asm("cdq");
	return 1;
}
