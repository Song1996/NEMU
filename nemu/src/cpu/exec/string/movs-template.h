#include "cpu/exec/template-start.h"

#define instr movs

make_helper(movs_b){
	int databyte=1;
	swaddr_write(cpu.edi,databyte,swaddr_read(cpu.esi,databyte));
	int temp=databyte;
	if(cpu.DF){cpu.esi-=temp;cpu.edi-=temp;}
	else{cpu.esi+=temp;cpu.edi+=temp;}
	print_asm("movsb");
	return 1;
}
/*
make_helper(movsw){
	int databyte=2;
	swaddr_write(cpu.edi,databyte,swaddr_read(cpu.esi,databyte));
	int temp=databyte;
	if(cpu.DF){cpu.esi-=temp;cpu.edi-=temp;}
	else{cpu.esi+=temp;cpu.edi+=temp;}
	print_asm("movsb");
	return 1;
}*/

make_helper(movs_v){
	int databyte=ops_decoded.is_data_size_16?2:4;
	swaddr_write(cpu.edi,databyte,swaddr_read(cpu.esi,databyte));
	int temp=databyte;
	if(cpu.DF){cpu.esi-=temp;cpu.edi-=temp;}
	else{cpu.esi+=temp;cpu.edi+=temp;}
	print_asm("movsb");
	return 1;
}

#include"cpu/exec/template-end.h"