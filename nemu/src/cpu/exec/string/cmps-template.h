#include "cpu/exec/template-start.h"

make_helper(concat(cmps_,SUFFIX))
{
	//assert(0);
		DATA_TYPE left=MEM_R(REG(R_ESI));
			DATA_TYPE right=MEM_R(REG(R_EDI));
				DATA_TYPE result=left-right;
					if(MSB(left)!=MSB(right) && MSB(left)!=MSB(result))
								cpu.OF=1;
						else
									cpu.OF=0;
							cpu.SF=!!MSB(result);
								cpu.ZF=!result;
									if(result>left)
												cpu.CF=1;
										else
													cpu.CF=0;
											int i,count=0;
												for(i=0;i<8;i++)
															if((result>>i)&0x1)	count++;
													if(count % 2) cpu.PF=0;
														else cpu.PF=1;
															if((result&0xF)>(left&0xF))
																		cpu.AF=1;
																else
																			cpu.AF=0;
																	if(DATA_BYTE==1) print_asm("cmpsb");
																		else if(DATA_BYTE==2) print_asm("cmpsw");
																			else print_asm("cmpsl");
																				return 1;
}


#include "cpu/exec/template-end.h"

