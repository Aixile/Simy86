#include "pipe.h"
#include "instruction.h"

pipe::pipe(void)
{
	f_addr=0;
	d_addr=e_addr=m_addr=w_addr=-1;
}


pipe::~pipe(void)
{
}

//###############################################
//Stage Fetch
std::pair<pipe::Fetch,pipe::Decode> pipe::Fetch::fetch(pipe::Memory &m,pipe::WriteBack &w,class memory &Mem){
	u32 pc=f_pc(m,w);
	std::pair<int,int> first_byte=get_byte(pc,Mem);
	int icode=1<<first_byte.first,ifun=first_byte.second;
	pc++;
	icode=f_icode(icode,Mem);ifun=f_ifun(ifun,Mem);	
	
	bool needRegid=Need_regids(icode);
	bool needValC=Need_valC(icode);
	int ra=RNONE,rb=RNONE;
	int valC=0;
	if(needRegid){
		std::pair<int,int> regid_byte=get_byte(pc,Mem);
		ra=regid_byte.first,rb=regid_byte.second;
		pc++;
	}
	if(needValC){
		valC=Mem.read(pc,4);
		pc+=4;
	}
	icode=f_icode(icode,Mem);ifun=f_ifun(ifun,Mem);	
	int stat=f_stat(icode,Mem);
	
	return std::pair<pipe::Fetch,pipe::Decode>(Fetch(f_predPC(icode,valC,pc)),Decode(stat,icode,ifun,ra,rb,valC,pc));
}

//Select PC
u32 pipe::Fetch::f_pc(pipe::Memory &m,pipe::WriteBack &w){
	if(m.icode==IJXX&&!m.cnd)	return m.valA;
	if(w.icode==IRET)	return w.valM;
	return predPC;
}

//Get a Byte from Instruction Memory
std::pair<int,int> pipe::Fetch::get_byte(u32 pc,class memory &Mem){
	int t=Mem.read(pc,1);
	return std::pair<int,int>(t>>4,t&0xF);
}

//Need valC ?
bool pipe::Fetch::Need_valC(int icode){
	return icode&(IIRMOVL|IRMMOVL|IMRMOVL|IJXX|ICALL);
}

//Need regid byte?
bool pipe::Fetch::Need_regids(int icode){
	return icode&(IRRMOVL|IOPL|IPUSHL|IPOPL|IIRMOVL|IRMMOVL|IMRMOVL);
}

//Predict PC
u32 pipe::Fetch::f_predPC(int icode,u32 valC,u32 valP){
	if(icode&(IJXX|ICALL))	return valC;
	return valP;
}

//Determine Memory Error of First Bype
int pipe::Fetch::f_icode(int icode,class memory &Mem){
	if(imem_error(Mem))	return INOP;
	return icode;
}

int pipe::Fetch::f_ifun(int ifun,class memory &Mem){
	if(imem_error(Mem))	return FNONE;
	return ifun;
}

//Is instruction valid ?
bool pipe::Fetch::instr_valid(int icode){
	return icode&(INOP|IHALT|IRRMOVL|IIRMOVL|IRMMOVL|IMRMOVL|IOPL|IJXX|ICALL|IRET|IPUSHL|IPOPL);
}

int pipe::Fetch::f_stat(int icode,class memory &Mem){
	if(imem_error(Mem))	return SADR;
	if(!instr_valid(icode))	return SINS;
	if(icode==IHALT)	return SHLT;
	return SAOK;
}

bool pipe::Fetch::imem_error(class memory &Mem){
	return Mem.isError();
}

//###############################################
//Stage Decode
pipe::Execute pipe::Decode::decode(Execute &e,Memory &m,WriteBack &w,class memory &Mem,conditioncode &cc,registerfile &Reg){
	return Execute(stat,icode,ifun,valC,d_valA(e,m,w,Mem,cc,Reg),d_valB(e,m,w,Mem,cc,Reg),d_dstE(),d_dstM(),d_srcA(),d_srcB());
}

int pipe::Decode::d_dstE(){
	if(icode&(IRRMOVL|IIRMOVL|IOPL))	return rb;
	if(icode&(IPUSHL|IPOPL|ICALL|IRET))	return RESP;
	return RNONE;

}

int pipe::Decode::d_dstM(){
	if(icode&(IMRMOVL|IPOPL))	return ra;
	return RNONE;
}

int pipe::Decode::d_srcA(){
	if(icode&(IRRMOVL|IRMMOVL|IOPL|IPUSHL))	return ra;
	if(icode&(IPOPL|IRET))	return RESP;
	return RNONE;
}

int pipe::Decode::d_srcB(){
	if(icode&(IOPL|IRMMOVL|IMRMOVL))	return rb;
	if(icode&(IPUSHL|IPOPL|ICALL|IRET))	return RESP;
	return RNONE;
}

int pipe::Decode::d_rvalA(registerfile &Reg){
	return Reg.read(d_srcA());
}

int pipe::Decode::d_rvalB(registerfile &Reg){
	return Reg.read(d_srcB());
}

int pipe::Decode::d_valA(Execute &e,Memory &m,WriteBack &w,class memory &Mem,conditioncode &cc,registerfile &Reg){
	if(icode&(ICALL|IJXX))	return valP;
	int srcA=d_srcA();
	if(srcA==RNONE)	return 0;
	if(srcA==e.e_dstE(cc))	return e.e_valE();
	if(srcA==m.dstM)	return m.m_valM(Mem);
	if(srcA==m.dstE)	return m.valE;
	if(srcA==w.dstM)	return w.valM;
	if(srcA==w.dstE)	return w.valE;
	return d_rvalA(Reg);
}

int pipe::Decode::d_valB(Execute &e,Memory &m,WriteBack &w,class memory &Mem,conditioncode &cc,registerfile &Reg){
	int srcB=d_srcB();
	if(srcB==RNONE)	return 0;
	if(srcB==e.e_dstE(cc))	return e.e_valE();
	if(srcB==m.dstM)	return m.m_valM(Mem);
	if(srcB==m.dstE)	return m.valE;
	if(srcB==w.dstM)	return w.valM;
	if(srcB==w.dstE)	return w.valE;
	return d_rvalB(Reg);
}

//###############################################
//Stage Execute
pipe::Memory pipe::Execute::execute(conditioncode &cc){
	return Memory(stat,icode,e_Cnd(cc),e_valE(),valA,e_dstE(cc),dstM);
}

bool pipe::Execute::set_cc(pipe::Memory &m,pipe::WriteBack &w,class memory &Mem){
	return icode==IOPL&&!(m.m_stat(Mem)&(SADR|SINS|SHLT))&&!(w.stat&(SADR|SINS|SHLT));
}

int pipe::Execute::aluA(){
	if(icode&(IRRMOVL|IOPL))	return valA;
	if(icode&(IIRMOVL|IRMMOVL|IMRMOVL))	return valC;
	if(icode&(ICALL|IPUSHL))	return -4;
	if(icode&(IRET|IPOPL))	return 4;
	return 0;
}

int pipe::Execute::aluB(){
	if(icode&(IRMMOVL|IMRMOVL|IOPL|ICALL|IPUSHL|IRET|IPOPL))	return valB;
	if(icode&(IRRMOVL|IIRMOVL))	return 0;
	return 0;
}

int pipe::Execute::alufun(){
	if(icode==IOPL)	return ifun;
	return ALUADD;
}

bool pipe::Execute::e_Cnd(conditioncode &cc){
	return cc.isTrue(ifun);
}

int pipe::Execute::e_dstE(conditioncode &cc){
	if(icode==IRRMOVL&&!e_Cnd(cc))	return RNONE;
	return dstE;
}

int pipe::Execute::e_valE(){
	int fun=alufun();
	int a=aluA(),b=aluB();
	int e=0;
	if(fun==ALUADD)	e=a+b;
	if(fun==ALUSUB)	e=b-a;
	if(fun==ALUAND) e=a&b;
	if(fun==ALUXOR)	e=a^b;
	return e;
}

conditioncode pipe::Execute::do_set_cc(){
	int fun=alufun();
	int a=aluA(),b=aluB();
	int e=0;
	conditioncode newcc;
	if(fun==ALUADD){
		e=a+b;
		newcc.update(e==0,e<0,(a<0==b<0)&&(e<0!=a<0));
	}
	if(fun==ALUSUB){
		e=b-a;
		newcc.update(e==0,e<0,(-a<0==b<0)&&(e<0!=-a<0));
	}
	if(fun==ALUAND){
		e=a&b;
		newcc.update(e==0,e<0,0);
	}
	if(fun==ALUXOR){
		e=a^b;
		newcc.update(e==0,e<0,0);
	}
	return newcc;
}

//###############################################
//Stage Memory 
pipe::WriteBack pipe::Memory::memory(class memory &Mem){
	return WriteBack(m_stat(Mem),icode,valE,m_valM(Mem),dstE,dstM);
}

u32 pipe::Memory::mem_addr(){
	if(icode&(IRMMOVL|IPUSHL|ICALL|IMRMOVL))	return valE;
	if(icode&(IPOPL|IRET))	return valA;
	return 0;
}

bool pipe::Memory::mem_read(){
	return icode&(IMRMOVL|IPOPL|IRET);
}

bool pipe::Memory::mem_write(){
	return icode&(IRMMOVL|IPUSHL|ICALL);
}

int pipe::Memory::m_stat(class memory &Mem){
	m_valM(Mem);
	if(Mem.isError())	return SADR;
	return stat;
}

int pipe::Memory::m_valM(class memory &Mem){
	if(mem_read())	return Mem.read(mem_addr(),4);
	if(mem_write())	 Mem.tryWrite(mem_addr(),4);
	return 0;
}

class memory pipe::Memory::write_memory(class memory &Mem){
	if(mem_write())	return Mem.writePresistent(mem_addr(),4,valA);
	return Mem;
}

//###############################################
//Stage WriteBack 
registerfile pipe::WriteBack::writeback(registerfile &Reg){
	registerfile new_reg=Reg;
	new_reg.write(dstE,valE);
	new_reg.write(dstM,valM);
	return new_reg;
}

//###############################################
//Pipeline Controller
struct pipe pipe::controller(){

	pipe::Fetch new_f;
	pipe::Decode new_d;
	pipe::Execute new_e;
	pipe::Memory new_m;
	pipe::WriteBack new_w;
	struct pipe new_pipe;
	new_pipe.cc=cc;
	new_pipe.Mem=Mem;
	new_pipe.Reg=Reg;
	std::pair<pipe::Fetch,pipe::Decode> fdtmp;

	if(F_stall())	new_f=Fetch(f.predPC),new_pipe.f_addr=f_addr;
	else{
		fdtmp=f.fetch(m,w,Mem);
		new_f=fdtmp.first;
		new_pipe.f_addr=new_f.predPC;
	}

	if(D_stall()){
		new_d=d;
		new_pipe.d_addr=d_addr;
	}else if(D_bubble()){
		new_d=Decode();
		new_pipe.d_addr=-1;
	}else new_d=fdtmp.second,new_pipe.d_addr=f.f_pc(m,w);

	if(E_bubble())	new_e=Execute(),new_pipe.e_addr=-1;
	else new_e=d.decode(e,m,w,Mem,cc,Reg),new_pipe.e_addr=d_addr;
	
	 new_w=m.memory(Mem);
	 new_pipe.w_addr=m_addr;

	 if(M_bubble())	new_m=Memory(),new_pipe.m_addr=-1;
	 else	new_m=e.execute(cc),new_pipe.m_addr=e_addr;
	
	if(m.mem_write())	new_pipe.Mem=m.write_memory(Mem);
	if(e.set_cc(m,w,Mem))	new_pipe.cc=e.do_set_cc();
	new_pipe.Reg=w.writeback(Reg);

	new_pipe.f=new_f;
	new_pipe.d=new_d;
	new_pipe.e=new_e;
	new_pipe.m=new_m;
	new_pipe.w=new_w;

	return new_pipe;
}


//Pipeline Control Logic
bool pipe::F_stall(){
	return (e.icode&(IMRMOVL|IPOPL))&&(e.dstM==d.d_srcA()||e.dstM==d.d_srcB())||
		(IRET&(d.icode|e.icode|m.icode));
}

bool pipe::D_stall(){
	return (e.icode&(IMRMOVL|IPOPL))&&(e.dstM==d.d_srcA()||e.dstM==d.d_srcB());
}

bool pipe::D_bubble(){
	return (e.icode==IJXX&&!e.e_Cnd(cc))||
		!(e.icode&(IMRMOVL|IPOPL))&&(e.dstM==d.d_srcA()||e.dstM==d.d_srcB())&&
		(IRET&(d.icode|e.icode|m.icode));
}

bool pipe::E_bubble(){
	return (e.icode==IJXX&&!e.e_Cnd(cc))||
		(e.icode&(IMRMOVL|IPOPL))&&(e.dstM==d.d_srcA()||e.dstM==d.d_srcB());
}

bool pipe::M_bubble(){
	return (m.m_stat(Mem)&(SADR|SINS|SHLT))||
		(w.stat&(SADR|SINS|SHLT));
}

bool pipe::W_stall(){
	return (w.stat&(SADR|SINS|SHLT));
}