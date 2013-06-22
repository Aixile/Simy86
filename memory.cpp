#include "memory.h"

// Trie Node Pool
TrieNode TrieNodePool[16*4*1000010];
int startNodeCnt;

memory::memory(void)
{
	error=0;
	TrieRoot=1;
}


memory::~memory(void)
{
}

int memory::readByte(u32 addr){
	int nowat=TrieRoot;
	for(int i=30;i>=0;i-=2){
		int dst=(addr>>i)&0x3;
		if(TrieNodePool[nowat].pos[dst]==0)	return 0;
		nowat=TrieNodePool[nowat].pos[dst];
	}
	return TrieNodePool[nowat].val;
}

int memory::read(u32 addr,int len){
	if(addr+(len-1)<addr||int(addr)<0){
		error=1;
		return 0;
	}
	if(len==1)	return readByte(addr);
	if(len==4)	return (readByte(addr+3)<<24)|(readByte(addr+2)<<16)|(readByte(addr+1)<<8)|readByte(addr);
	return 0;
}

void memory::writeByte(u32 addr,int w){
	int nowat=TrieRoot;
	for(int i=30;i>=0;i-=2){
		int dst=(addr>>i)&0x3;
		if(TrieNodePool[nowat].pos[dst]==0){
			TrieNodePool[nowat].pos[dst]=++startNodeCnt;
			memset(TrieNodePool+startNodeCnt,0,sizeof(TrieNode));
		};
		nowat=TrieNodePool[nowat].pos[dst];
	}
	TrieNodePool[nowat].val=w;
}

void memory::write(u32 addr,int len,int w){
	if(addr+(len-1)<addr){
		error=1;
		return;
	}
	if(int(addr)<0){
		error=1;
		return;
	}
	if(len==1)	writeByte(addr,w);
	if(len==4){
		writeByte(addr,w&0xFF);w>>=8;
		writeByte(addr+1,w&0xFF);w>>=8;
		writeByte(addr+2,w&0xFF);w>>=8;
		writeByte(addr+3,w&0xFF);
	}
}

int memory::writeBytePresistent(int TrieRoot,u32 addr,int w){
	int nowat=TrieRoot;
	int dstAt=++startNodeCnt;
	int newRoot=dstAt;

	for(int i=30;i>=0;i-=2){
		int dst=(addr>>i)&0x3;
		TrieNodePool[dstAt]=TrieNodePool[nowat];
		TrieNodePool[dstAt].pos[dst]=++startNodeCnt;
		memset(TrieNodePool+startNodeCnt,0,sizeof(TrieNode));
		nowat=TrieNodePool[nowat].pos[dst];
		dstAt=TrieNodePool[dstAt].pos[dst];
	}
	TrieNodePool[dstAt].val=w;
	return newRoot;
}

memory memory::writePresistent(u32 addr,int len,int w){
	if(addr+(len-1)<addr){
		error=1;
		return memory(TrieRoot,error);
	}
	if(int(addr)<0){
		error=1;
		return memory(TrieRoot,error);;
	}
	if(len==1)	return memory(writeBytePresistent(TrieRoot,addr,w),error);
	if(len==4){
		int newroot=writeBytePresistent(TrieRoot,addr,w&0xFF);w>>=8;
		newroot=writeBytePresistent(newroot,addr+1,w&0xFF);w>>=8;
		newroot=writeBytePresistent(newroot,addr+2,w&0xFF);w>>=8;
		newroot=writeBytePresistent(newroot,addr+3,w&0xFF);
		return memory(newroot,error);
	}
	return memory(TrieRoot,error);
}

bool memory::isError(){
	return error;
}

void memory::clearError(){
	error=0;
}

void memory::clear(){
	TrieRoot=startNodeCnt=1;
	memset(TrieNodePool,0,2*sizeof(TrieNode));
	error=false;
}

void memory::tryWrite(u32 addr,int len){
	if(addr+(len-1)<addr){
		error=1;
		return;
	}
	if(int(addr)<0){
		error=1;
		return;
	}
}