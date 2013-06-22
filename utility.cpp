#include "utility.h"

int byte2int(char *s){
	int a=0,b=0;
	if(s[0]>='0'&&s[0]<='9')	a=s[0]-'0';
	else a=s[0]-'a'+10;
	if(s[1]>='0'&&s[1]<='9')	b=s[1]-'0';
	else b=s[1]-'a'+10;
	return a*16+b;
}

char fourbit2hex(int a){
	if(a>=0&&a<10)	return '0'+a;
	else return 'A'-10+a;
}

std::string int2byte(int a){
	std::string s="";
	s+=fourbit2hex((a>>4)&0xf);
	s+=fourbit2hex((a>>0)&0xf);
	return s;
}

std::string int2hexStr(int a){
	std::string s="0x";
	s+=fourbit2hex((a>>28)&0xf);
	s+=fourbit2hex((a>>24)&0xf);
	s+=fourbit2hex((a>>20)&0xf);
	s+=fourbit2hex((a>>16)&0xf);
	s+=fourbit2hex((a>>12)&0xf);
	s+=fourbit2hex((a>>8)&0xf);
	s+=fourbit2hex((a>>4)&0xf);
	s+=fourbit2hex((a>>0)&0xf);
	return s;
}

std::string int2hexStr12bit(int a){
	if(a>0xFFF)	return int2hexStr(a);
	std::string s="0x";
	s+=fourbit2hex((a>>8)&0xf);
	s+=fourbit2hex((a>>4)&0xf);
	s+=fourbit2hex((a>>0)&0xf);
	return s;
}

std::string int2hexStr4bit(int a){
	if(a>0xF)	return int2hexStr12bit(a);
	std::string s="0x";
	s+=fourbit2hex((a>>0)&0xf);
	return s;
}

std::string bit2tf(int a){
	if(a&1)	return std::string("true");
	else	return std::string("false");
}

std::string int2str(int a){
	std::string s="";
	if(a==0)	return s+'0';
	while(a){
		char t=fourbit2hex(a%10);
		s=t+s;
		a/=10;
	}
	return s;
}

int mylog2(int a){
	int ans=0;
	while(a>1)	ans++,a>>=1;
	return ans;
}

std::string getState(int a,int addr){
	if(addr==-1)	return std::string("BUB");
	if(a==1)	return std::string("AOK");
	if(a==2)	return std::string("ADR");
	if(a==4)	return std::string("INS");
	else		return std::string("HLT");
}

std::string getReg(int a){
	if(a==0)	return std::string("EAX");
	if(a==1)	return std::string("ECX");
	if(a==2)	return std::string("EDX");
	if(a==3)	return std::string("EBX");
	if(a==4)	return std::string("ESP");
	if(a==5)	return std::string("EBP");
	if(a==6)	return std::string("ESI");
	if(a==7)	return std::string("EDI");
	return std::string("---");
}

std::string getIcode(int a){
	if(a==0)	return std::string("HALT");
	if(a==1)	return std::string("NOP");
	if(a==2)	return std::string("RRMOV");
	if(a==3)	return std::string("IRMOV");
	if(a==4)	return std::string("RMMOV");
	if(a==5)	return std::string("MRMOV");
	if(a==6)	return std::string("OP");
	if(a==7)	return std::string("JXX");
	if(a==8)	return std::string("CALL");
	if(a==9)	return std::string("RET");
	if(a==10)	return std::string("PUSH");
	if(a==11)	return std::string("POP");
	return std::string("ERR");
}


std::string getIfun(int icode ,int ifun){
	if(icode==6){
		if(ifun==0)	return std::string("ADD");
		if(ifun==1)	return std::string("SUB");
		if(ifun==2)	return std::string("AND");
		if(ifun==3)	return std::string("XOR");
	}
	if(icode==7){
		if(ifun==0)	return std::string("JMP");
		if(ifun==1)	return std::string("JLE");
		if(ifun==2)	return std::string("JL");
		if(ifun==3)	return std::string("JE");
		if(ifun==4)	return std::string("JNE");
		if(ifun==5)	return std::string("JGE");
		if(ifun==6)	return std::string("JG");
	}
	if(icode==1||icode==2||icode>11)	return std::string("---");
	return std::string("ADD");
}