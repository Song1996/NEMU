#include "cpu/exec/template-start.h"

#define instr movzx

make_helper(concat(movzx_rm2r_,SUFFIX))
{
	int len=concat(decode_rm2r_,SUFFIX)(eip+1);
	uint8_t result=op_src->val;
	OPERAND_W(op_dest,result);
	print_asm_template2();
	return len+1;
}
make_helper(concat(movzx2_rm2r_,SUFFIX))
{
	int len=concat(decode_rm2r_,SUFFIX)(eip+1);
	uint16_t result=op_src->val;
	OPERAND_W(op_dest,result);
	print_asm_template2();
	return len+1;
}
//make_helper(rm2r)

#include "cpu/exec/template-end.h"
