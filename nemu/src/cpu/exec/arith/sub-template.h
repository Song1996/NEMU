#include "cpu/exec/template-start.h"

#define instr sub

static void do_execute(){
	DATA_TYPE left=op_dest->val;
	DATA_TYPE right=op_src->val;
	DATA_TYPE result=left-right;	
	OPERAND_W(op_dest, result);
	
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2r)
//#if DATA_BYTE==2||DATA_BYTE==4
//make_instr_helper(sib2rm)
//#endif
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"
