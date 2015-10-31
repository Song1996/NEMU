#include "cpu/exec/template-start.h"

#define instr call

static void do_execute(){
	int src = op_src->val;
	cpu.esp-=4;
	if(DATA_BYTE==2)assert(0);
	swaddr_write(cpu.esp,4,cpu.eip+5);
	cpu.eip += src;
	//printf("call $0x%x",src);
	print_asm_template1();
	
}
//#if DATA_BYTE==2||DATA_BYPE==4
make_instr_helper(i)
//#endif
/*
make_helper(call_rm_w)
{
	int len=concat(decode_rm_,w)(eip+1);
	uint32_t src=op_src->val;
	cpu.esp-=4;
	swaddr_write(cpu.esp,4,cpu.eip+len+1);
	cpu.eip=src;
	print_asm_template1();
	return len+1;
}
make_helper(call_rm_l)
{
	int len=concat(decode_rm_,l)(eip+1);
	uint32_t src=op_src->val;
	cpu.esp-=4;
	swaddr_write(cpu.esp,4,cpu.eip+len+1);
	cpu.eip=src;
	print_asm_template1();
	return len+1;
}
*/
#include "cpu/exec/template-end.h"
