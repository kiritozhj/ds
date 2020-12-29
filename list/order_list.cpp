#include <iostream>
#include <cstdlib>
using namespace std;
#define Maxsize 10

typedef struct{
    int len,maxsize;
    int* data;
}node;

void InitList(node& L);
int Length(node& L);
int GetElem(node& L,int i);
int LocateElem(node& L,int e);
void ListInsert(node& L,int i,int e);
void ListDelete(node& L,int i);
void PrintList(node& L);
bool Empty(node& L);
void DestroyList(node& L);

void InitList(node& L){
    L.len=0;
    L.maxsize=Maxsize;
    L.data=(int*)malloc(sizeof(int)*L.maxsize);
    for(int i=0;i<L.maxsize;++i){
        L.data[i]=0;
    }
}

int Length(node& L){
    return L.len;
}

int GetElem(node& L,int i){
    return L.data[i-1];
}

int LocateElem(node& L,int e){
    int len=Length(L);
    for(int i=1;i<=len;++i){
        if(e!=GetElem(L,i)) continue;
        else return i;
    }
    return -1;
}

void ListInsert(node& L,int i,int e){
    if(Length(L)==L.maxsize){
        L.maxsize=L.maxsize*2+1;
        int* temp=(int*)malloc(sizeof(int)*L.maxsize);
        for(int j=0;j<Length(L);++j){
            temp[j]=GetElem(L,j+1);
        }
        L.data=temp;
    }
    for(int j=Length(L);j>=i;--j){
        L.data[j]=GetElem(L,j);
    }
    L.data[i-1]=e;
    ++L.len;
}

void ListDelete(node& L,int i){
    for(int j=i;j<=Length(L);++j){
        L.data[j-1]=GetElem(L,j+1);
    }
    --L.len;
}

void PrintList(node& L){
    int num=Length(L);
    for(int i=0;i<num;++i){
        printf("%d:%d\n",i+1,GetElem(L,i+1));
    }
}

bool Empty(node& L){
    return L.len;
}

void DestroyList(node& L){
    free(L.data);
}

int main(){
    node list;
    InitList(list);
    for(int i=0;i<10;++i){
        list.data[i]=i;
    }
    list.len=10;
    PrintList(list);
    DestroyList(list);
}
