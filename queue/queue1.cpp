#include<iostream>
using namespace std;
#define maxSize 100

typedef struct{
	int data[maxSize];
	int front;
	int rear;
}SqQueue;

void initQueue(SqQueue &qu){
	qu.front=qu.rear=0;
}

int isEmpty(SqQueue qu){
	if(qu.front==qu.rear)
		return 1;
	else
		return 0;
}

int enQueue(SqQueue &qu,int x){
	if((qu.rear+1)%maxSize==qu.front)
		return 0;
	qu.rear=(qu.rear+1)%maxSize;
	qu.data[qu.rear]=x;
	return 1;
}

int deQueue(SqQueue &qu,int &x){
	if((qu.rear+1)%maxSize==qu.front)
		return 0;
	qu.front=(qu.front+1)%maxSize;
	x=qu.data[qu.front];
	return 1;
}

int main()
{
	
}
