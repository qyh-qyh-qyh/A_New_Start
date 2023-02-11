#include<stdio.h>
#include<stdlib.h>
//这些操作默认为无向图和有权图 

//专业程序员一。这已经是一个图结构了，只不过为了方便反复调用，弄成一个结构体 
struct GNode{
	int nv;
	int ne;
	int gr[100][100];//表示的是顶点与顶点的关系 
	char data[100];//表示顶点的数据 
};
typedef struct GNode* PtrToGNode;

typedef PtrToGNode MGraph;//问题一。为什么要通过一个中间值来确定这个 

typedef int Vertex;//专业程序员二。用这个来区分正常整型数据和一般整型数

struct EdgeNode{
	Vertex v1,v2;
	int weight;//权重 
};

typedef struct EdgeNode* PointToEdge;

typedef PointToEdge Edge; 

//问题二。先创立一个只初始化了结点的图
MGraph CreateGraph(int Vertexnum){
    Vertex i,j; 
	MGraph g;
	g=(MGraph)malloc(sizeof(struct GNode));
	g->nv=Vertexnum;
	g->ne=0;
//	Vertex i,j;
	for(i=0;i<Vertexnum;i++){
		for(j=0;j<Vertexnum;j++){
		   g->gr[i][j]=0;	
		}
	}
	return g; 
}

//问题三。在建立好顶点的图中插入边
void CreateEdge(MGraph g,Edge e){
	g->gr[e->v1][e->v2]=e->weight;
	g->gr[e->v2][e->v1]=e->weight;
}

MGraph BuildGraph(){
	MGraph Graph;
	Edge E;//记得声明变量 
	Vertex VN;
	int EN;
	int i;
	scanf("%d",&VN);
	Graph=CreateGraph(VN);
	scanf("%d",&EN);
	E=(Edge)malloc(sizeof(struct EdgeNode));//问题四。这里要先建立一个储存编数据的结点，别忘记在前面声明 
	for(i=0;i<EN;i++){
		scanf("%d%d%d",&E->v1,&E->v2,&E->weight);
		CreateEdge(Graph,E);
	}
	for(i=0;i<Graph->nv;i++){
		scanf("%c",&Graph->data[i]);//问题五。这里表示顶点中储存的数据 
	}
	return Graph;
}
 
