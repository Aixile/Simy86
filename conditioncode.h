#pragma once

//Condition code file implement
class conditioncode
{
private:
	int cc;
public:
	conditioncode(void);
	conditioncode(int zf,int sf,int of);
	~conditioncode(void);
	void update(int v);
	void update(int zf,int sf,int of);
	bool isTrue(int fun);
	int isZF();
	int isSF();
	int isOF();
};
