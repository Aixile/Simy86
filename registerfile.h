#pragma once
#include <string.h>

//Regiter File Implement
class registerfile
{
private:
	int reg[8];
	int error;
public:
	registerfile(void);
	~registerfile(void);
	int read(int addr);
	void write(int addr,int w);
	bool isError();
};
