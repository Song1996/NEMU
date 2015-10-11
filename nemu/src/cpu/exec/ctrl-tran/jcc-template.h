#include "cpu/exec/template-start.h"



make_helper(concat(ja_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if((!cpu.CF)&&(!cpu.ZF))
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}








make_helper(concat(je_i_, SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.ZF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}


#include "cpu/exec/template-end.h"
