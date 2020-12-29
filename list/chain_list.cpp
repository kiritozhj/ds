#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node;

void InitList(node& L);
int Length(node& L);
int LocateElem(node& L,int e);
int GetElem(node& L,int i);
void ListInsert(node& L,int i,int e);
void ListDelete(node& L,int i);
void PrintList(node& L);
bool Empty(node& L);
void DestroyList(node& L);

void InitList(node& L){
    L.data=0;
    L.next=nullptr;
}
int Length(node& L){
    node* temp=L.next;
    int num=0;
    while(temp){
        ++num;
        temp=temp->next;
    }
    return num;
}
int LocateElem(node& L,int e){
    node* temp=L.next;
    int i=1;
    while(temp){
        if(temp->data==e) return i;
        else{
            ++i;
            temp=temp->next;
        }
    }
    return -1;
}
int GetElem(node& L,int i){
    node* temp=L.next;
    while(i-1){
        --i;
        temp=temp->next;
        if(!temp){
            printf("error!");
            return -1;
        }
    }
    return temp->data;
}
void ListInsert(node& L,int i,int e){
    node* cur=&L;
    while(i-1){
        --i;
        cur=cur->next;
    }
    node* temp=(node*)malloc(sizeof(node));
    temp->data=e;
    temp->next=cur->next;
    cur->next=temp;
}
void ListDelete(node& L,int i){
    node* cur=L.next;
    while(i-2){
        --i;
        cur=cur->next;
    }
    node* temp=cur->next;
    cur->next=cur->next->next;
    free(temp);
}
void PrintList(node& L){
    node* temp=L.next;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
bool Empty(node& L){
    return L.next;
}
void DestroyList(node& L){
    node* cur=L.next;
    node* temp;
    if(!cur) return;
    while(cur){
        temp=cur->next;
        free(cur);
        cur=temp;
    }
}

int main(){
    node a;
    InitList(a);
    for(int i=0;i<10;++i){
        ListInsert(a,i+1,i);
    }
    ListInsert(a,3,100);
    ListDelete(a,4);
    cout<<GetElem(a,3)<<endl;
    PrintList(a);
    DestroyList(a);
    PrintList(a);
}
