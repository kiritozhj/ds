#include<iostream>
#include<queue>
#include<map>
using namespace std;

#define maxsize 100
struct node{
	char data;
	struct node* next;
};

struct header{
	char data;
	node* first;
};

struct graph{
	header list[maxsize];
	int n,e;
};

map<char,int> coss;
graph* init(){
	char litter;
	graph* g=(graph*)malloc(sizeof(graph));
	printf("please input the number of vertexs:");
	scanf("%d%c",&g->n,&litter);	
	for(int i=0;i<g->n;++i){
		printf("input no %d :",i+1);
		scanf("%c%c",&g->list[i].data,&litter);
		coss[g->list[i].data]=i;
	}
	for(int i=0;i<g->n;++i){
		g->list[i].first=nullptr;
		int mark;
		for(int j=0;j<g->n;++j){
			if(i==j) continue;
			printf("input relationship between %c and %c :",g->list[i].data,g->list[j].data);
			scanf("%d%c",&mark,&litter);
			if(!mark) continue;
			node* new_node=(node*)malloc(sizeof(node));
			new_node->data=g->list[j].data;
			new_node->next=nullptr;
			if(g->list[i].first){
				node* temp=g->list[i].first;
				g->list[i].first=new_node;
				new_node->next=temp;
			}else{
				g->list[i].first=new_node;
			}
		}
	}
	return g;
}

map<char,bool> visited;
void bfs(graph* g,int v){
	node* p;
	queue<node*> Q;
	printf("%c",g->list[v].data);
	visited[g->list[v].data]=true;
	node temp;
	Q.push(&temp);
	while(!Q.empty()){
		Q.pop();
		p=g->list[v].first;
		while(p){
			if(!visited[p->data]){
				printf("%c",p->data);
				visited[p->data]=true;
				Q.push(p);
			}
			p=p->next;
		}
	}
}

void dfs(graph* g,int v){
	printf("%c",g->list[v].data);
	visited[g->list[v].data]=true;
	node* p=g->list[v].first;
	while(p){
		if(!visited[p->data])
			dfs(g,coss[p->data]);
		p=p->next;
	}
}

int main(){ 
	graph* g=init();
	//bfs(g,0);
	dfs(g,0);
}
