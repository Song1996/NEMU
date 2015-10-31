#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "call-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "call-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "call-template.h"
#undef DATA_BYTE

make_helper_v(call_i)

make_helper(call_rm_w)
{
	int len=concat(decode_rm_,w)(eip+1);
	uint32_t src=op_src->val;
	cpu.esp-=4;
	swaddr_write(cpu.esp,4,cpu.eip+len+1);
	cpu.eip=src-2;
	print_asm_template1();
	return len+1;
}
make_helper(call_rm_l)
{
	int len=concat(decode_rm_,l)(eip+1);
	uint32_t src=op_src->val;
	cpu.esp-=4;
	swaddr_write(cpu.esp,4,cpu.eip+len+1);
	cpu.eip=src-2;
	print_asm_template1();
	return len+1;
}

make_helper_v(call_rm)
