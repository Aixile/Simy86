#ifndef REGISTER_H
#define REGISTER_H

#define REAX 0
#define RECX 1
#define REDX 2
#define REBX 3
#define RESP 4
#define REBP 5
#define RESI 6
#define REDI 7
#define RNONE 15

#define IHALT 1
#define INOP 2
#define IRRMOVL 4
#define IIRMOVL 8
#define IRMMOVL 16
#define IMRMOVL 32
#define IOPL 64
#define IJXX 128
#define ICALL 256
#define IRET 512
#define IPUSHL 1024
#define IPOPL 2048

#define FNONE 0
#define ALUADD 0
#define ALUSUB 1
#define ALUAND 2
#define ALUXOR 3

#define SAOK 1
#define SADR 2
#define SINS 4
#define SHLT 8

#define CCJMP 0
#define CCJLE 1
#define CCJL 2
#define CCJE 3
#define CCJNE 4
#define CCJGE 5
#define CCJG 6
typedef unsigned int u32;
#endif