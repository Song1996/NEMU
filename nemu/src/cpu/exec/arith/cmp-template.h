#include "cpu/exec/template-start.h"

#define instr cmp

static void do_execute(){
	DATA_TYPE left = op_dest->val;
	DATA_TYPE right = op_src->val;
	DATA_TYPE result = left - right;
	DATA_TYPE min=(0x1<<(DATA_BYTE*8-1));
	//cpu.OF = (MSB(left)==MSB(right))&&(MSB(left)!=MSB(result));
	cpu.OF = (left<min && right>=min && result>=min)||(left>=min && right<min && result<min)||(left==0 && right==min);
	cpu.SF = !!MSB(result);
	cpu.ZF = !result;
	cpu.CF = (result>left);
	int i = 0;
	DATA_TYPE copy = result;
	int bit = 1;
	for(i=0;i<8;i++)
	{
		bit^=(copy&1);
		copy>>=1;
	}
	cpu.PF=bit;
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2r)
#if DATA_BYTE==2||DATA_BYTE==4
make_instr_helper(si2rm)
#endif
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"	
