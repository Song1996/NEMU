#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "movs-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "movs-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "movs-template.h"
#undef DATA_BYTE

make_helper_v(movs)
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









