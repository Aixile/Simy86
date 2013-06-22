#include "conditioncode.h"
#include "conditioncode.h"
#include "instruction.h"


conditioncode::conditioncode(void)
{
	cc=0;
}


conditioncode::~conditioncode(void)
{
}

conditioncode::conditioncode(int zf,int sf,int of){
	cc=(zf<<2)|(sf<<1)|of;
}

void conditioncode::update(int v){
	cc=v;
}

void conditioncode::update(int zf,int sf,int of){
	cc=(zf<<2)|(sf<<1)|of;
}

bool conditioncode::isTrue(int fun){
	bool zf=(cc>>2)&1,sf=(cc>>1)&1,of=cc&1;
	if(fun==CCJE)	return zf;
	if(fun==CCJNE)	return !zf;
	if(fun==CCJL)	return sf^of;
	if(fun==CCJLE)	return (sf^of)|zf;
	if(fun==CCJG)	return (!(sf^of))&(!zf);
	if(fun==CCJGE)	return !(sf^of);
	return true;
}

int conditioncode::isZF(){
	return (cc>>2)&1;
}

int conditioncode::isSF(){
	return (cc>>1)&1;
}

int conditioncode::isOF(){
	return cc&1;
}

