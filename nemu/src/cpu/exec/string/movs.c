#include "cpu/exec/helper.h"
/*
#define DATA_BYTE 1
#include "movs-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "movs-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "movs-template.h"
#undef DATA_BYTE
*/
//make_helper_v(movs)
/*
make_helper(movs_b){
	int databyte=1;
	swaddr_write(cpu.edi,databyte,swaddr_read(cpu.esi,databyte));
	if(cpu.DF){cpu.esi-=databyte;cpu.edi-=databyte;}
	else{cpu.esi+=databyte;cpu.edi+=databyte;}
	print_asm("movsb");
	return 1;
}

make_helper(movs_v){
	int databyte=4;
	swaddr_write(cpu.edi,databyte,swaddr_read(cpu.esi,databyte));
	if(cpu.DF){cpu.esi-=databyte;cpu.edi-=databyte;}
	else{cpu.esi+=databyte;cpu.edi+=databyte;}
	print_asm("movsd");
	return 1;
}
*/


#define DATA_BYTE 1

	make_helper(movs_b)
{
		swaddr_write(cpu.edi,DATA_BYTE,swaddr_read(cpu.esi,DATA_BYTE));
			if(cpu.DF)
					{
											cpu.esi-=DATA_BYTE;
																cpu.edi-=DATA_BYTE;
																	}else
																			{
																									cpu.esi+=DATA_BYTE;
																														cpu.edi+=DATA_BYTE;
																															}	
																		print_asm("movsb" " %%ds:(%%esi),%%es:(%%edi)");
																			return 1;	
}
#undef DATA_BYTE

make_helper(movs_v)
{
		char c='l';
			int n;
				if( ops_decoded.is_data_size_16)
						{
								n=2;
										c='w';
											}
					else n=4;
						swaddr_write(cpu.edi,n,swaddr_read(cpu.esi,n));
							if(cpu.DF)
									{
															cpu.esi-=n;
																				cpu.edi-=n;
																					}else
																							{
																													cpu.esi+=n;
																																		cpu.edi+=n;
																																			}
																							
																						print_asm("movs"  "%c %%ds:(%%esi),%%es:(%%edi)",c);
																							return 1;
}


