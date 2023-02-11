#include<stdio.h>
#include<stdlib.h>
//问题一。一共有四种结构体，一种表示每一个邻接结点，一种表示每个结点有和它相连的边，一种是边，最后一种就是图 
typedef int Vertex;

//typedef AdjVNode* PointToAdjVNode; 

 struct AdjVNode{
	Vertex AdjV;//表示结点下标 
	int weight;//表示边的权重
	PointToAdjVNode next;
};
typedef AdjVNode* PointToAdjVNode; 

typedef struct VNode{
	PointToAdjNode FirstEdge;
	int data;
}AdjList;

typedef struct GNode{
	int vn;
	int en;
	AdjList G[100];
};

typedef struct GNode* PointToGNode;

typedef PointToGNode LGraph;

struct ENode{
	Vertex v1,v2;
	int weight;
};

typedef struct ENode* PointToEdge;

typedef PointToEdge Edge;

//问题二，与邻接矩阵一样，也是三步走建立一个只有顶点的图 
LGraph CreateGraph(int Vertexnum){
	LGraph g;
	g=(LGraph)malloc(sizeof(GNode));
	g->vn=Vertexnum;
	g->en=0;
	int i;
	for(i=0;i<Vertexnum;i++){
		g->G[i].FirstEdge=NULL;
	}
	return g;
}

//问题三，分两大步，每一步三小步分别建立起v1到v2和v2到v1的边 
void InsertEdge(LGraph g,Edge e){
	//第一步，申请一个新空间 
    PointToAdjNode NewNode;
    NewNode=(PointToAdjNode)malloc(sizeof(AdjNode));
    //第二步，将边结点的内容存入新建立的邻接结点之中 
	NewNode->AdjV=Edge->v2;
	NewNode->weight=Edge->weight;
	//第三步，头插 
	NewNode->next=g->G[v1].FirstEdge;	
}


