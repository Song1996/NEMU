#include "cpu/exec/template-start.h"

#define instr adc
/*
static void do_execute()
{
	DATA_TYPE left=op_dest->val;
	DATA_TYPE right=op_src->val+cpu.CF;
	DATA_TYPE result=left+right;
	//OPERAND_W(op_dest,result);
	uint64_t z=(uint64_t)op_src->val+(uint64_t)cpu.CF+(uint64_t)left;
	cpu.OF=((MSB(left)==MSB(right))&&MSB(right)!=MSB(result));
	cpu.CF=!!(z>(uint64_t)result);
	cpu.SF=!!MSB(result);
	cpu.ZF=!result;
	int i=0;
	DATA_TYPE copy=result;
	int bit =1;
	for(i=0;i<8;i++)
	{
		bit^=(copy&1);
		copy>>=1;
	}
	cpu.PF=bit;
	OPERAND_W(op_dest,result);
	print_asm_template2();
}*/



static void do_execute () {
		unsigned n=sizeof(DATA_TYPE)*8-1;
			DATA_TYPE dest=op_dest->val;
				DATA_TYPE src=op_src->val+cpu.CF;

					DATA_TYPE result = op_dest->val + op_src->val+cpu.CF;
						OPERAND_W(op_dest, result);

							uint64_t temp=(uint64_t)src+dest;
								cpu.CF=!!(temp>>(n+1));
									if(MSB(dest)==MSB(src)&&MSB(result)!=MSB(src))
											{
														cpu.OF=1;
															}else
																					cpu.OF=0;
																cpu.ZF=!result;
																	cpu.SF=(result>>n)&1;
																		bool bit=result&1;
																			int i;
																				for(i=0;i<7;i++)
																						{
																									result>>=1;
																											bit^=result&1;
																												}
																					cpu.PF=!bit;

																						print_asm_template2();
}


make_instr_helper(i2a)
make_instr_helper(i2rm)
#if DATA_BYTE==2||DATA_BYTE==4
make_instr_helper(si2rm)
#endif
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"
