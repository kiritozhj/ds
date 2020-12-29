#include<iostream>
using namespace std;

#define vertex_num 100 //顶点数目
typedef char vertex_type; //顶点的数据类型
typedef int edge_type; //权值或者连通性
typedef struct{
	vertex_type vex[vertex_num]; //顶点表
	edge_type edge[vertex_num][vertex_num]; //边表
	int vexnum,arcnum; //图的当前顶点数和边数
}graph; //图的邻接矩阵,用来存储梗概信息




