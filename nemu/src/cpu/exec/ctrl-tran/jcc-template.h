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

make_helper(concat(jae_i_,SUFFIX))
{
    int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(!cpu.CF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jb_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.CF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jbe_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.CF||cpu.ZF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jc_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.CF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jcxz_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(reg_w(R_CX)==0)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jecxz_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.ecx==0)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jz_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.ZF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jg_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if((!cpu.ZF)&&(cpu.SF==cpu.OF))
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jge_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.SF==cpu.OF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jl_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.SF!=cpu.OF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jle_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.ZF||cpu.SF!=cpu.OF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jna_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.CF||cpu.ZF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jnae_i_,SUFFIX))
{
	int len=concat(decode_i_,SUFFIX)(eip+1);
	int src=op_src->val;
	if(cpu.CF)
		cpu.eip+=src;
	print_asm_template1();
	return len+1;
}
























#include "cpu/exec/template-end.h"
