#include<stdio.h>
#include<stdlib.h>
//����һ��һ�������ֽṹ�壬һ�ֱ�ʾÿһ���ڽӽ�㣬һ�ֱ�ʾÿ������к��������ıߣ�һ���Ǳߣ����һ�־���ͼ 
typedef int Vertex;

//typedef AdjVNode* PointToAdjVNode; 

 struct AdjVNode{
	Vertex AdjV;//��ʾ����±� 
	int weight;//��ʾ�ߵ�Ȩ��
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

//����������ڽӾ���һ����Ҳ�������߽���һ��ֻ�ж����ͼ 
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

//�������������󲽣�ÿһ����С���ֱ�����v1��v2��v2��v1�ı� 
void InsertEdge(LGraph g,Edge e){
	//��һ��������һ���¿ռ� 
    PointToAdjNode NewNode;
    NewNode=(PointToAdjNode)malloc(sizeof(AdjNode));
    //�ڶ��������߽������ݴ����½������ڽӽ��֮�� 
	NewNode->AdjV=Edge->v2;
	NewNode->weight=Edge->weight;
	//��������ͷ�� 
	NewNode->next=g->G[v1].FirstEdge;	
}


