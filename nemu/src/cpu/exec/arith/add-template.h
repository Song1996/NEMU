#include "cpu/exec/template-start.h"

#define instr add

static void do_execute()
{
	DATA_TYPE left=op_dest->val;
	DATA_TYPE right=op_src->val;
	DATA_TYPE result=left+right;
	OPERAND_W(op_dest,result);
	//cpu.OF=((MSB(left)==MSB(right))&&MSB(left)!=MSB(result));
	DATA_TYPE min=(0x1<<(DATA_BYTE*8-1));
	cpu.OF = (left<min && right>=min && result>=min)||(left>=min && right<min &&result<min)||(left==0 && right==min);
	long long unsigned temp=(long long unsigned)left+right;
	if(result==temp)cpu.CF=0;
	else	cpu.CF=1;
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
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2rm)
#if DATA_BYTE==2||DATA_BYTE==4
make_instr_helper(si2rm)
#endif
make_instr_helper(r2rm)
make_instr_helper(rm2r)

/*
make_helper(add_si2rm_v)
{
	int left=op_dest->val;
	int right=op_src->val;
	int result=left+right;
	OPERAND_W(op_dest,result);
	cpu.OF=((MSB(left)==MSB(right))&&MSB(left)!=MSB(result));
	cpu.CF=(result>left);
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
	print_asm_template2();
	
}*/

#include "cpu/exec/template-end.h"
