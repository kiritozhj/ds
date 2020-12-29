#include<iostream>
using namespace std;
int* getnext(string s){
    int* next=new int[10];
    size_t i=0,j=1;
    next[1]=0;
    while(j<s.size()){
        if(i==0||s[j]==s[i]){
            ++i;
            ++j;
            next[j]=i;
        }else
            i=next[i];
    }
    return next;
}
void print(int* arr,int len){
    for(int i=0;i<len;++i)
        printf("%d ",arr[i]);
}
int main(){
    string a="abababb";
    int* next=getnext(a);
    print(next,(int)a.size());
}
