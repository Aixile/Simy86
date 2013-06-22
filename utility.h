#pragma once
#include <string>
#include <fstream>

//Utilities

 //string form byte to 4bit int 
int byte2int(char *s);

//4 bit int to a hex character
char fourbit2hex(int a); 

//log2 Function
int mylog2(int a); 

//8bit int to std string form byte 
std::string int2byte(int a); 

//int to std string 
std::string int2hexStr(int a); 

//12 bit int to std string 
std::string int2hexStr12bit(int a); 

//4bit int to std string   
std::string int2hexStr4bit(int a); 

//1bit to std string form true/false 
std::string bit2tf(int a);

//int to std string
std::string int2str(int a);

//get icode hint
std::string getIcode(int a);

//get function hint
std::string getIfun(int icode,int ifun);

//get state hint 
std::string getState(int a,int addr);

//get register name hibnt
std::string getReg(int a);