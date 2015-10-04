#include "cpu/exec/template-start.h"

#define instr test

static void do_execute(){
	DATA_TYPE left=op_dest->val;
	DATA_TYPE right=op_src->val;
	DATA_TYPE result=left&right;
	OPERAND_W(op_dest,result);
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
	cpu.CF=0;
	cpu.OF=0;
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)

#include "cpu/exec/template-end.h"
