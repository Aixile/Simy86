#pragma once
# include "instruction.h"
# include "memory.h"
# include "registerfile.h"
# include "conditioncode.h"


struct  pipe
{
	memory Mem;
	registerfile Reg;
	conditioncode cc;
	pipe(void);
	~pipe(void);

//	memory address of instruction in f,d,e,m,w stage
	int f_addr,d_addr,e_addr,m_addr,w_addr;

	typedef struct WriteBack{
		int stat,icode,valE,valM,dstE,dstM;

		WriteBack(int stat=SAOK,int icode=INOP,int valE=0,int valM=0,int dstE=RNONE,int dstM=RNONE):
			stat(stat),icode(icode),valE(valE),valM(valM),dstE(dstE),dstM(dstM){}
		registerfile writeback(registerfile &Reg);
	} WriteBack;

	 typedef struct Memory{
		int stat,icode,cnd,valE,valA,dstE,dstM;

		Memory(int stat=SAOK,int icode=INOP,bool cnd=true,int valE=0,int valA=0,int dstE=RNONE,int dstM=RNONE):
			stat(stat),icode(icode),cnd(cnd),valE(valE),valA(valA),dstE(dstE),dstM(dstM){}
		WriteBack memory(class memory &Mem);
		class memory write_memory(class memory &Mem);
		int m_valM(class memory &Mem);
		int m_stat(class memory &Mem);
		u32 mem_addr();
		bool mem_read();
		bool mem_write();
	} Memory;

	typedef struct Execute{
		int stat,icode,ifun,valC,valA,valB,dstE,dstM,srcA,srcB;

		Execute(int stat=SAOK,int icode=INOP,int ifun=FNONE,int valC=0,int valA=0,int valB=0,int dstE=RNONE,int dstM=RNONE,int srcA=RNONE,int srcB=RNONE):
			stat(stat),icode(icode),ifun(ifun),valC(valC),valA(valA),valB(valB),dstE(dstE),dstM(dstM),srcA(srcA),srcB(srcB){}
		Memory execute(conditioncode &cc);
		int e_dstE(conditioncode &cc);
		int e_valE();
		bool set_cc(Memory &m,WriteBack &w,class memory &Mem);
		int aluA();
		int aluB();
		int alufun();
		bool e_Cnd(conditioncode &cc);
		conditioncode do_set_cc();
	} Execute;

	typedef struct Decode{
		int stat,icode,ifun,ra,rb,valC,valP;

		Decode(int stat=SAOK,int icode=INOP,int ifun=FNONE,int ra=RNONE,int rb=RNONE,int valC=0,int valP=0):
			stat(stat),icode(icode),ifun(ifun),ra(ra),rb(rb),valC(valC),valP(valP){}
		Execute decode(Execute &e,Memory &m,WriteBack &w,class memory &Mem,conditioncode &cc,registerfile &Reg);
		int d_dstE();
		int d_dstM();
		int d_srcA();
		int d_srcB();
		int d_rvalA(registerfile &Reg);
		int d_rvalB(registerfile &Reg);
		int d_valA(Execute &e,Memory &m,WriteBack &w,class memory &Mem,conditioncode &cc,registerfile &Reg);
		int d_valB(Execute &e,Memory &m,WriteBack &w,class memory &Mem,conditioncode &cc,registerfile &Reg);
	} Decode;

	typedef struct Fetch{
		u32 predPC;
		Fetch(u32 predPC=0):predPC(predPC){}
		std::pair<Fetch,Decode> fetch(Memory &m,WriteBack &w,class memory &Mem);
		u32 f_pc(Memory &m, WriteBack &w);
		std::pair<int,int> get_byte(u32 pc,class memory &Mem);
		bool Need_valC(int icode);
		bool Need_regids(int icode);
		u32 f_predPC(int icode,u32 valP,u32 valC);
		int f_icode(int icode,class memory &Mem);
		int f_ifun(int ifun,class memory &Mem);
		bool instr_valid(int icode);
		int f_stat(int icode,class memory &Mem);
		bool imem_error(class memory &Mem);
	} Fetch;

	Fetch f;
	Decode d;
	Execute e;
	Memory m;
	WriteBack w;

//	Follow pipeline control logic to get next pipeline state
	pipe controller();

	bool F_stall();
	bool D_stall();
	bool D_bubble();
	bool E_bubble();
	bool M_bubble();
	bool W_stall();
} ;
