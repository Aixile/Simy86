#pragma once
#include <map>
#include "instruction.h"


//Trie Node Struct
struct TrieNode{
	int pos[4];
	int val;
};

//Memory implement
//Use Presistent Trie Tree
class memory
{
private:


public:
	int TrieRoot;
	int error;
	memory(void);
	memory(int TrieRoot,int error):TrieRoot(TrieRoot),error(error){}
	~memory(void);
	
	int read(u32 addr,int len=1);
	int readByte(u32 addr);

//	write and change TrieRoot
	void writeByte(u32 addr,int w);
	void write(u32 addr,int len=1,int w=0);

//	write and return a new TrieRoot
	int writeBytePresistent(int TrieRoot,u32 addr,int w);
	memory writePresistent(u32 addr,int len,int w);

//	TryWrite and set error flag
	void tryWrite(u32 addr,int len=1);

	bool isError();
	void clearError();

//	Clear All and reset startNodeCnt	
	void clear();
};

