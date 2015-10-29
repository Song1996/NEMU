#include "cpu/exec/template-start.h"

#define instr jmp

make_helper(concat(jmp_si_,SUFFIX)){
	int len=concat(decode_si_,SUFFIX)(eip+1);
	int src=op_src->val;
	printf("%d\n",src);
	cpu.eip+=src;
	print_asm_template1();
	return len+1;
}

make_helper(concat(jmp_rm_,SUFFIX)){
	//int len=concat(decode_rm_,SUFFIX)(eip+1);
	int src=op_src->val;
	printf("****");
	cpu.eip=src;
	print_asm_template1();
	return 0;
}

//make_instr_helper(si)
//make_instr_helper(rm)

#include "cpu/exec/template-end.h"
