#include<iostream>
using namespace std;
#define maxsize 100
#define INF 65535

struct graph{
    int arr[maxsize][maxsize],n;
};

graph* init(){
    graph* g=(graph*)malloc(sizeof(graph));
    printf("input the number of points:");
    scanf("%d",&g->n);
    for(int i=0;i<g->n;++i){
        for(int j=i+1;j<g->n;++j){
            printf("input the length between %d and %d:",i+1,j+1);
            scanf("%d",&g->arr[i][j]);
            if(!g->arr[i][j]) g->arr[i][j]=INF;
            g->arr[j][i]=g->arr[i][j];
        }
    }
    return g;
}

graph* prim(graph* g,int start){
    graph* new_g=(graph*)malloc(sizeof(graph));
    new_g->n=g->n;
    int visited[g->n],lowcost[g->n],min,cur;
    for(int i=0;i<g->n;++i){
        lowcost[i]=g->arr[start-1][i];
        if(g->arr[start-1][i]){
            visited[i]=start-1;
        }
        visited[i]=0;
    }
    for(int i=1;i<g->n;++i){
        min=INF;
        for(int j=0;j<g->n;++j){
            if(lowcost[j]&&lowcost[j]<min){
                min=lowcost[j];
                cur=j;
            }
        }
        printf("%d->%d\n",visited[cur]+1,cur+1);
        lowcost[cur]=0;
        for(int j=0;j<g->n;++j){
            if(lowcost[j]&&g->arr[cur][j]<lowcost[j]){
                lowcost[j]=g->arr[cur][j];
                visited[j]=cur;
            }
        }
    }
    return new_g;
}

void kruskal(graph* g){
     
}

void print(graph* g){
    for(int i=0;i<g->n;++i){
        for(int j=0;j<g->n;++j){
            printf("%d\t",g->arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    graph* g=init();
    graph* new_g=prim(g,2);
    //print(new_g);
}
