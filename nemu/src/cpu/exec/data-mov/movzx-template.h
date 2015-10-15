#include "cpu/exec/template-start.h"

#define instr movzx

make_helper(concat(movzx_rm2r_,SUFFIX))
{
	int len=concat(decode_rm2r_,SUFFIX)(eip+1);
	unsigned int src=op_src->val;
	if (DATA_BYTE==1)
	{
		src<<=24;
		src>>=24;
	}
	else if(DATA_BYTE==2)
	{
		src<<=16;
		src>>=16;	
	}
	//else
	//	nemu_assert();
	OPERAND_W(op_dest,src);
	print_asm_template2();
	return len+1;
}

#include "cpu/exec/template-end.h"
