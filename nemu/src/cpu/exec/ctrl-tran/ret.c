#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "ret-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "ret-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "ret-template.h"
#undef DATA_BYTE

make_helper_v(ret)

make_helper(ret_si)
{
	concat(decode_si_,w)(eip+1);
	int src=op_src->val;
	cpu.eip=swaddr_read(cpu.esp,4);
	cpu.esp+=4;
	cpu.eip+=src;
	cpu.eip--;
	return 3;
}


#undef DATA_BYTE

