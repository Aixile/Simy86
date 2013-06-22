#include "registerfile.h"
#include "instruction.h"


registerfile::registerfile(void)
{
	memset(reg,0,sizeof(reg));
}


registerfile::~registerfile(void)
{
}

int registerfile::read(int addr){
	if(addr<0||addr>=8){
		if(addr==RNONE)	error=0;
		else	error=1;
		return 0;
	}
	error=0;
	return reg[addr];
}

void registerfile::write(int addr,int w){
	if(addr<0||addr>=8){
		if(addr==RNONE) error=0;
		else	error=1;
		return;
	}
	error=0;
	addr[reg]=w;
}