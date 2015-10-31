#include "cpu/exec/template-start.h"

#define instr adc

static void do_execute()
{
	DATA_TYPE left=op_dest->val;
	DATA_TYPE right=op_src->val+cpu.CF;
	DATA_TYPE result=left+right;
	//OPERAND_W(op_dest,result);
	uint64_t z=(uint64_t)op_src->val+(uint64_t)cpu.CF+(uint64_t)left;
	cpu.OF=((MSB(left)==MSB(right))&&MSB(right)!=MSB(result));
	cpu.CF=!!(z>(uint64_t)result);
	cpu.SF=!!MSB(result);
	cpu.ZF=!result;
	int i=0;
	DATA_TYPE copy=result;
	int bit =1;
	for(i=0;i<8;i++)
	{
		bit^=(copy&1);
		copy>>=1;
	}
	cpu.PF=bit;
	OPERAND_W(op_dest,result);
	print_asm_template2();
}


make_instr_helper(i2a)
make_instr_helper(i2rm)
#if DATA_BYTE==2||DATA_BYTE==4
make_instr_helper(si2rm)
#endif
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"
