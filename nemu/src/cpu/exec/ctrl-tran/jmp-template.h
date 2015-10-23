#include "cpu/exec/template-start.h"

#define instr jmp

make_helper(concat(jmp_si_,SUFFIX)){
	int len=concat(decode_si_,SUFFIX)(eip+1);
	int src=op_src->val;
	cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jmp_rm_,SUFFIX)){
	int len=concat(decode_rm_,SUFFIX)(eip+1);
	int src=op_src->val;
	cpu.eip=src;
	print_asm_template1();
	return len+1;
}

//make_instr_helper(si)
//make_instr_helper(rm)

#include "cpu/exec/template-end.h"
