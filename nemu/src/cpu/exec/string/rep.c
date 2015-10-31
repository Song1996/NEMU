#include "cpu/exec/helper.h"

make_helper(exec);

make_helper(rep) {
	int len=1;
	int count = 0;
	//assert(0);
	if(instr_fetch(eip + 1, 1) == 0xc3) {
		/* repz ret */
		//printf("***\n");
		exec(eip + 1);
		len = 0;
	}
	else {
		//printf("%d\n",cpu.ecx);	
		//printf("%d\n\n",len);
		while(cpu.ecx) {
			//printf("%d\n",cpu.ecx);
			exec(eip + 1);
			//printf("%d\n",cpu.ecx);	
			//break;
			count ++;
			cpu.ecx --;
			assert(ops_decoded.opcode == 0xa4	// movsb
				|| ops_decoded.opcode == 0xa5	// movsw
				|| ops_decoded.opcode == 0xaa	// stosb
				|| ops_decoded.opcode == 0xab	// stosw
				|| ops_decoded.opcode == 0xa6	// cmpsb
				|| ops_decoded.opcode == 0xa7	// cmpsw
				|| ops_decoded.opcode == 0xae	// scasb
				|| ops_decoded.opcode == 0xaf	// scasw
				);
			//if(count>100000)break;
			/* TODO: Jump out of the while loop if necessary. */

		}
		len = 1;
	}

#ifdef DEBUG
	char temp[80];
	sprintf(temp, "rep %s", assembly);
	sprintf(assembly, "%s[cnt = %d]", temp, count);
#endif
	//printf("%d\n",len);	
	return len + 1;
}
