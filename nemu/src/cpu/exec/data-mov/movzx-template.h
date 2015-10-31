#include "cpu/exec/template-start.h"

#define instr movzx
#if DATA_BYTE==2||DATA_BYTE==4
make_helper(concat(movzx_rm2r_,SUFFIX))
{
	//assert(0);
	int len=concat(decode_rm2r_,SUFFIX)(eip+1);
	uint8_t result=op_src->val;
	DATA_TYPE temp=result;
	OPERAND_W(op_dest,temp);
	print_asm_template2();
	return len+1;
}
make_helper(concat(movzx2_rm2r_,SUFFIX))
{
	//assert(0);
	int len=concat(decode_rm2r_,SUFFIX)(eip+1);
	uint16_t result=op_src->val;
	DATA_TYPE temp=result;
	OPERAND_W(op_dest,temp);
	print_asm_template2();
	return len+1;
}
#endif
//make_helper(rm2r)

#include "cpu/exec/template-end.h"
