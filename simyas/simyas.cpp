#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
FILE *yyin,*outfile;
char read_s[512],s[512],sss[512],s1[50],s2[50];
char infname[512],outfname[512];
int line;//当前执行的行号
int line_pos[2000],min_pos,max_pos;
int tag_tot,tag_pos[2000],tag_line[2000];
bool legal;
map<string,int>map_reg,map_opl,map_jxx,map_cmovxx,map_tag;
map<string,int>::iterator iter;
void print_error(int line){
	fprintf(stderr, "error: in line %d\n", line);
}
void print_warning(int line){
	fprintf(stderr, "warning: in line %d\n", line);
}
void pinrt_tag_error(int line1,int line2,char *s){
	fprintf(stderr, "error: the %s be used in line %d and line %d\n",s,line1,line2);
}
bool string_to_int(char *s,int &xxx){
	int len=strlen(s),i;
	if(len==0)return 0;
	memcpy(sss,s,strlen(s)+1);
	for(i=0;i<len;i++)if(sss[i]>='A'&&sss[i]<='Z')sss[i]=sss[i]+32;
	if(len<2){
		xxx=0;
		if(sss[0]>='0'&&sss[0]<='9'){xxx=sss[0]-'0';return 1;}
		return 0;
	}
	memset(s2,0,sizeof(s2));
	if(sss[0]=='-'){
		for(i=1;i<len;i++)s2[i-1]=sss[i];
		len--;
	}else for(i=0;i<len;i++)s2[i]=sss[i];
	xxx=0;
	if(s2[1]=='x'){
		for(i=2;i<len;i++)if((s2[i]<'0'||s2[i]>'9')&&(s2[i]<'a'||s2[i]>'f'))
			break;
		else{
			if(s2[i]<='9')xxx=xxx*16+s2[i]-'0';
			else xxx=xxx*16+10+s2[i]-'a';
		}
		if(i<len)return 0;
	}else{
		for(i=0;i<len;i++)if(s2[i]<'0'||s2[i]>'9'){
			break;
		}else{
			xxx=xxx*10+s2[i]-'0';
		}
		if(i<len)return 0;
	}
	if(s[0]=='-')xxx*=-1;
	return 1;
}
bool read_memory(char *s,int &xxx,int &reg){
	int len=strlen(s),p,i;
	if(len<=2)return 0;
	for(p=0;p<len;p++)if(s[p]=='(')break;
	if(p==len)return 0;
	if(p>0){
		memset(s1,0,sizeof(s1));
		for(i=0;i<p;i++)s1[i]=s[i];
		if(!string_to_int(s1,xxx))return 0;
	}else xxx=0;
	memset(s1,0,sizeof(s1));
	for(i=p+1;i<len-1;i++)s1[i-p-1]=s[i];
	iter=map_reg.find(s1);
	if(iter==map_reg.end())return 0;
	reg=iter->second;
	return 1;
}
void init_map_reg(){
	map_reg.clear();
	map_reg.insert(pair<string,int>("%eax",0));
	map_reg.insert(pair<string,int>("%ecx",1));
	map_reg.insert(pair<string,int>("%edx",2));
	map_reg.insert(pair<string,int>("%ebx",3));
	map_reg.insert(pair<string,int>("%esp",4));
	map_reg.insert(pair<string,int>("%ebp",5));
	map_reg.insert(pair<string,int>("%esi",6));
	map_reg.insert(pair<string,int>("%edi",7));	
}
void init_map_tag(){
	map_tag.clear();
}
void init_map_jxx(){
	map_jxx.clear();
	map_jxx.insert(pair<string,int>("jmp",0));
	map_jxx.insert(pair<string,int>("jle",1));
	map_jxx.insert(pair<string,int>("jl",2));
	map_jxx.insert(pair<string,int>("je",3));
	map_jxx.insert(pair<string,int>("jne",4));
	map_jxx.insert(pair<string,int>("jge",5));
	map_jxx.insert(pair<string,int>("jg",6));
}
void init_map_cmovxx(){
	map_cmovxx.clear();
	map_cmovxx.insert(pair<string,int>("cmovle",1));
	map_cmovxx.insert(pair<string,int>("cmovl",2));
	map_cmovxx.insert(pair<string,int>("cmove",3));
	map_cmovxx.insert(pair<string,int>("cmovne",4));
	map_cmovxx.insert(pair<string,int>("cmovge",5));
	map_cmovxx.insert(pair<string,int>("cmovg",6));
}
void init_map_opl(){
	map_opl.clear();
	map_opl.insert(pair<string,int>("addl",0));
	map_opl.insert(pair<string,int>("subl",1));
	map_opl.insert(pair<string,int>("andl",2));
	map_opl.insert(pair<string,int>("xorl",3));
}
void init(){
	init_map_reg();
	init_map_jxx();
	init_map_cmovxx();
	init_map_opl();
	min_pos=~0u>>1;max_pos=-1;
}
bool solve1(int line){
	int i,num,xxx,reg;
	char *ss[10];
	memset(s,0,sizeof(s));
	memcpy(s,read_s,sizeof(s));	
	int len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='#'){
			len=i;break;
		}
		if(s[i]==',')s[i]=' ';
	}
	int pos=line_pos[line],now=1;
	line_pos[line+1]=pos;
	if(len==0||(len==1&&(s[0]==' '||s[0]=='\n'||s[0]=='	'))){
		return 1;
	}
	s[len]='\0';
	memset(ss,0,sizeof(ss));
	ss[1]=strtok(s," 	$\n");num=1;
	while(ss[num++]!=NULL){
		ss[num]=strtok(NULL," 	$\n");
	}num-=2;
	if(num==0){	
		return 1;
	}

	if(strcmp(ss[1],".pos")==0){
		if(num!=2){
			print_error(line);
			return 0;
		}
		if(!string_to_int(ss[2],line_pos[line])){
			print_error(line);
			return 0;
		}
		if(line_pos[line]<=max_pos&&line_pos[line]>=min_pos){
			print_warning(line);
		}
		pos=line_pos[line];
		min_pos=min(min_pos,pos);
		max_pos=max(max_pos,pos);
		line_pos[line+1]=pos;
		
		return 1;
	}else
		if(strcmp(ss[1],".align")==0){
			if(num==2){
				int xxx;
				if(!string_to_int(ss[2],xxx)){
					print_error(line);
					return 0;
				}
				while(line_pos[line]%xxx)line_pos[line]++;
				pos=line_pos[line];
				line_pos[line+1]=pos;
			}else{
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
	if(ss[1][strlen(ss[1])-1]==':'){
		int l=strlen(ss[1]);ss[1][l-1]='\0';
		iter=map_tag.find(ss[1]);
		if(iter==map_tag.end()){
			map_tag.insert(pair<string,int>(ss[1],++tag_tot));
			tag_pos[tag_tot]=pos;
			tag_line[tag_tot]=line;
		}else{
			pinrt_tag_error(line,tag_line[iter->second],ss[1]);
			//fprintf(stderr, "error: the "%s" be used in line "%d" and line "%d"\n",ss[1],line,tag_line[iter->second]);
			return 0;
		}
		if((ss[now][0]<'a'||ss[now][0]>'z')&&(ss[now][0]<'A'||ss[now][0]>'Z')){
			print_error(line);
			return 0;
		}
		now=2;
		min_pos=min(min_pos,pos);
		max_pos=max(max_pos,pos);
		if(now>num)return 1;
	}
	for(now;now<=num;now++){
		int l=strlen(ss[now]);
		if(ss[now][l-1]==':'){
			print_error(line);
			return 0;
		}
		if(strcmp(ss[now],".long")==0){
			if(now+1!=num){
				print_error(line);
				return 0;
			}else
				if(!string_to_int(ss[now+1],xxx)){
					print_error(line);
					return 0;
				}
			line_pos[line+1]+=4;
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"halt")==0){
			line_pos[line+1]++;
			if(now<num){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"nop")==0){
			line_pos[line+1]++;
			if(now<num){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"rrmovl")==0){
			if(now+2!=num){
				print_error(line);
				return 0;
			}		
			line_pos[line+1]+=2;		
			iter=map_reg.find(ss[now+1]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			iter=map_reg.find(ss[now+2]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"irmovl")==0){
			line_pos[line+1]+=6;		
			if(now+2!=num){
				print_error(line);
				return 0;
			}
			if(!string_to_int(ss[now+1],xxx)){
				if(0){//init:	irmovl Stack, %esp
					print_error(line);
					return 0;
				}
			}
			iter=map_reg.find(ss[now+2]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"rmmovl")==0){
			line_pos[line+1]+=6;		
			if(now+2!=num){
				print_error(line);
				return 0;
			}
			iter=map_reg.find(ss[now+1]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			if(!read_memory(ss[now+2],xxx,reg)){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"mrmovl")==0){
			line_pos[line+1]+=6;
			if(now+2!=num){
				print_error(line);
				return 0;
			}
			if(!read_memory(ss[now+1],xxx,reg)){
				print_error(line);
				return 0;
			}
			iter=map_reg.find(ss[now+2]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(map_opl.find(ss[now])!=map_opl.end()){
			line_pos[line+1]+=2;
			if(now+2!=num){
				print_error(line);
				return 0;
			}
			iter=map_reg.find(ss[now+1]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			iter=map_reg.find(ss[now+2]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(map_jxx.find(ss[now])!=map_jxx.end()){
			line_pos[line+1]+=5;
			if(now+1!=num){
				print_error(line);
				return 0;
			}		
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;			
		}
		if(map_cmovxx.find(ss[now])!=map_cmovxx.end()){
			line_pos[line+1]+=2;
			if(now+1!=num){
				print_error(line);
				return 0;
			}			
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"call")==0){
			line_pos[line+1]+=5;
			if(now==num||now+2<num){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"ret")==0){
			line_pos[line+1]+=1;
			if(now<num){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"pushl")==0){
			line_pos[line+1]+=2;
			iter=map_reg.find(ss[now+1]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			if(now+1<num){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		if(strcmp(ss[now],"popl")==0){
			line_pos[line+1]+=2;
			iter=map_reg.find(ss[now+1]);
			if(iter==map_reg.end()){
				print_error(line);
				return 0;
			}
			if(now+1<num){
				print_error(line);
				return 0;
			}
			min_pos=min(min_pos,pos);
			max_pos=max(max_pos,pos);
			return 1;
		}
		print_error(line);
		return 0;
	}
	
	min_pos=min(min_pos,pos);
	max_pos=max(max_pos,pos);
	return 1;
}

void d_to_x(int xxx,int out_s[30],int l){
	out_s[l+1]=xxx&15;xxx>>=4;
	out_s[l+0]=xxx&15;xxx>>=4;
	out_s[l+3]=xxx&15;xxx>>=4;
	out_s[l+2]=xxx&15;xxx>>=4;
	out_s[l+5]=xxx&15;xxx>>=4;
	out_s[l+4]=xxx&15;xxx>>=4;
	out_s[l+7]=xxx&15;xxx>>=4;
	out_s[l+6]=xxx&15;xxx>>=4;
}
void solve2(FILE *out){
	int i,num,out_s[30],reg;
	char outs[27],*ss[10];
	memset(s,0,sizeof(s));
	memcpy(s,read_s,sizeof(s));
	read_s[strlen(read_s)-1]='\0';
	int len=strlen(s),ll=0;
	fprintf(out,"0x%08x: ",line_pos[line]);
	for(i=0;i<len;i++){
		if(s[i]=='#'){
			len=i;break;
		}
		if(s[i]==',')s[i]=' ';
	}
	if(len==0||(len==1&&(s[0]==' '||s[0]=='\n'||s[0]=='	'))){
		fprintf(out,"                      |");
		fprintf(out,"%s",read_s);
		return;
	}
	s[len]='\0';
	memset(ss,0,sizeof(ss));
	ss[1]=strtok(s," 	$\n");num=1;
	while(ss[num++]!=NULL){
		ss[num]=strtok(NULL," 	$\n");
	}num-=2;
	if(num==0){
		fputs("                      |",out);
		fputs(read_s,out);
		return;
	}
	if(strcmp(ss[1],".pos")==0||strcmp(ss[1],".align")==0){
		fputs("                      |",out);
		fputs(read_s,out);
		return;
	}
	int now=1;
	if(ss[1][strlen(ss[1])-1]==':'){
		now=2;
	}
	memset(out_s,0,sizeof(out_s));
	for(now;now<=num;now++){
		int l=strlen(ss[now]),xxx;
		if(strcmp(ss[now],".long")==0){
			ll=8;
			string_to_int(ss[now+1],xxx);
			d_to_x(xxx,out_s,0);
			break;
		}
		if(strcmp(ss[now],"halt")==0){
			ll=2;
			break;
		}
		if(strcmp(ss[now],"nop")==0){
			ll=2;
			out_s[0]=1;
			break;
		}
		if(strcmp(ss[now],"rrmovl")==0){
			ll=4;
			iter=map_reg.find(ss[now+1]);
			out_s[2]=iter->second;
			iter=map_reg.find(ss[now+2]);
			out_s[3]=iter->second;
			out_s[0]=2;
			break;
		}
		if(strcmp(ss[now],"irmovl")==0){
			ll=12;
			if(!string_to_int(ss[now+1],xxx)){
				iter=map_tag.find(ss[now+1]);
				if(iter==map_tag.end()){
					legal=0;
					print_error(line);return;
				}else
					d_to_x(tag_pos[iter->second],out_s,4);
			}else d_to_x(xxx,out_s,4);
			iter=map_reg.find(ss[now+2]);
			out_s[0]=3;out_s[2]=15;
			out_s[3]=iter->second;
			break;
		}
		if(strcmp(ss[now],"rmmovl")==0){
			ll=12;
			out_s[0]=4;
			iter=map_reg.find(ss[now+1]);
			out_s[2]=iter->second;
			read_memory(ss[now+2],xxx,reg);
			out_s[3]=reg;
			d_to_x(xxx,out_s,4);
			break;
		}
		if(strcmp(ss[now],"mrmovl")==0){
			ll=12;
			out_s[0]=5;
			iter=map_reg.find(ss[now+2]);
			out_s[2]=iter->second;
			read_memory(ss[now+1],xxx,reg);
			out_s[3]=reg;
			d_to_x(xxx,out_s,4);
			break;
		}
		if(map_opl.find(ss[now])!=map_opl.end()){
			ll=4;
			iter=map_opl.find(ss[now]);
			out_s[0]=6;out_s[1]=iter->second;
			iter=map_reg.find(ss[now+1]);
			out_s[2]=iter->second;
			iter=map_reg.find(ss[now+2]);
			out_s[3]=iter->second;
			break;
		}
		if(map_jxx.find(ss[now])!=map_jxx.end()){
			ll=10;
			iter=map_jxx.find(ss[now]);
			out_s[0]=7;out_s[1]=iter->second;
			iter=map_tag.find(ss[now+1]);
			if(iter==map_tag.end()){
				legal=0;
				print_error(line);return;
			}else
				d_to_x(tag_pos[iter->second],out_s,2);
			break;
		}
		if(map_cmovxx.find(ss[now])!=map_cmovxx.end()){
			ll=4;
			iter=map_cmovxx.find(ss[now]);
			out_s[0]=2;out_s[1]=iter->second;
			iter=map_reg.find(ss[now+1]);
			out_s[2]=iter->second;
			iter=map_reg.find(ss[now+2]);
			out_s[3]=iter->second;
			break;
		}
		if(strcmp(ss[now],"call")==0){
			ll=10;
			out_s[0]=8;
			iter=map_tag.find(ss[now+1]);
			if(iter==map_tag.end()){
				legal=0;
				print_error(line);return;
			}else
				d_to_x(tag_pos[iter->second],out_s,2);
			break;
		}
		if(strcmp(ss[now],"ret")==0){
			ll=2;out_s[0]=9;
			break;
		}
		if(strcmp(ss[now],"pushl")==0){
			ll=4;
			iter=map_reg.find(ss[now+1]);
			out_s[0]=10;out_s[2]=iter->second;
			out_s[3]=15;
			break;
		}
		if(strcmp(ss[now],"popl")==0){
			ll=4;
			iter=map_reg.find(ss[now+1]);
			out_s[0]=11;out_s[2]=iter->second;
			out_s[3]=15;
			break;
		}
	}
	for(i=0;i<ll;i++)fprintf(out,"%x",out_s[i]);
	for(i=ll+1;i<=22;i++)fprintf(out," ");
	fprintf(out,"|");
	fputs(read_s,out);
}

int main(int argc, char *argv[]){
	int rootlen=strlen(argv[1]);
	strncpy(infname,argv[1],rootlen);
	yyin=fopen(infname,"r");//打开输入文件
	if(!yyin){//无法打开文件
		fprintf(stderr, "Can't open input file '%s'\n", infname);		
		return 0;
	}
	strncpy(outfname,argv[1],rootlen-1);
	strcpy(outfname+rootlen-1,"o");
	outfile=fopen(outfname,"w");//打开输出文件
	legal=1;
	init();
	while(fgets(read_s,500,yyin)!=NULL){
		++line;
		if(solve1(line)==0)legal=0;
		//else fprintf(stderr,"OK %d\n",line);
	}
	if(!legal){
		system("pause");
		return 0;
	}
	yyin=fopen(infname,"r");//打开输入文件
	tag_tot=0;
	line=0;
	while(fgets(read_s,500,yyin)!=NULL){
		++line;
		solve2(outfile);
		fprintf(outfile,"\n");
	}
	if(legal==1){
		fprintf(stderr,"OK\n");
	}
	system("pause");
}
