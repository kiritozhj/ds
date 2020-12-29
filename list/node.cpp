#include<iostream>
//#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
}node;

node* create(const char* path){
	freopen(path,"r",stdin);
	int temp;
	node* start=(node*)malloc(sizeof(node));
	start->next=NULL;
	while(cin>>temp){
		node* a=(node*)malloc(sizeof(node));
		a->data=temp;
		a->next=NULL;
		node* b=start;
		while(b->next){
			b=b->next;
		}
		b->next=a;
	}
	fclose(stdin);
	return start;
}

node* head_create(const char* path){
	freopen(path,"r",stdin);
	int temp;
	node* start=(node*)malloc(sizeof(node));
	start->next=nullptr;
	while(cin>>temp){
		node* new_node=(node*)malloc(sizeof(node));
		new_node->data=temp;
		if(start->next)
			new_node->next=start->next;
		start->next=new_node;
	}
	fclose(stdin);
	return start;
}

void prt(node* start){
	//node* temp=start;
	//int i=0;
	while(start->next){
		start=start->next;
		cout<<start->data;
		//i++;
	}
	
}

void _delete(node* start){
	node* a=start->next;
	while(a->next){
		if(a->data==a->next->data){
			node* temp=a->next;
			a->next=a->next->next;
			free(temp);
		}else{
			a=a->next;
		}
	}
}

void _delete_min(node* start){
	node* temp=start->next,*p=start->next->next,*pre=start;
	while(p){
		if(p->data<temp->data){
			temp=p;
			pre=pre->next;
		}
		p=p->next;
	}
	node* _delete=pre->next;
	pre->next=temp->next;
	free(_delete);
}

void reverse(node* start){
	node* p=start->next,*q;
	start->next=NULL;
	while(p)
	{
		q=p->next;
		p->next=start->next;
		start->next=p;
		p=q;
	}
}

void split(node* a,node*& b){
	node *p,*q,*r;
	b=(node*)malloc(sizeof(node));
	b->next=NULL;

	r=b;
	p=a;
	while(p->next!=NULL){
		if(p->next->data%2==0){
			q=p->next;
			p->next=q->next;
			q->next=NULL;
			r->next=q;
			r=q;
		}
		else p=p->next;
	}
}

node* init(){
	node* a=(node*)malloc(sizeof(node));
	a->next=NULL;
	return a;
}

void r_prt(node *start){
	if(start->next){
		r_prt(start->next);
		cout<<start->data;
	}else{
		cout<<start->data;
	}
}

int main()
{
	node* a=head_create("./data.txt");
	prt(a);
	cout<<endl;
	reverse(a);
	prt(a);
}
