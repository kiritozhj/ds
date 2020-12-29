#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct{
	char *ch;
	int length;
}Str;

void init(Str &str){
	str.ch=NULL;
	str.length=0;
}

int strassign(Str& str,const char *ch)
{
	if(str.ch)
		free(str.ch);
	int len=0;
	const char *c=ch;
	while(*c){
		++len;
		++c;
	}
	if(len==0){
		str.ch=NULL;
		str.length=0;
		return 1;
	}else{
		str.ch=(char*)malloc(sizeof(char)*(len+1));
		if(str.ch==NULL)
			return 0;
		else{
			c=ch;
			for(int i=0;i<=len;++i,++c)
				str.ch[i]=*c;
			str.length=len;
			return 1;
		}
	}
}

int strlength(Str str){
	return str.length;
}

int strcompare(Str s1,Str s2){
	for(int i=0;i<s1.length&&i<s2.length;++i)
		if(s1.ch[i]!=s2.ch[i])
			return s1.ch[i]-s2.ch[i];
	return s1.length-s2.length;
}

int main()
{
	Str str1,str2;
	init(str1);init(str2);
	strassign(str1,"asd");
	strassign(str2,"qwe");
	cout<<strcompare(str1,str2);
}
