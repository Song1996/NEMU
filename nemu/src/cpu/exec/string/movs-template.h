#include "cpu/exec/template-start.h"

#define instr movs

make_helper(concat(movs_,SUFFIX)){
	swaddr_write(cpu.edi,DATA_BYTE,swaddr_read(cpu.esi,DATA_BYTE));
	int temp=DATA_BYTE;
	if(cpu.DF){
		cpu.esi-=temp;
		cpu.edi-=temp;
	}
	else{
		cpu.esi+=temp;
		cpu.edi+=temp;
	}
	if(DATA_BYTE==1)print_asm("movsb");
	else if(DATA_BYTE==2)print_asm("movsw");
	else print_asm("movsl");
	return 1;
}

#include"cpu/exec/template-end.h"
