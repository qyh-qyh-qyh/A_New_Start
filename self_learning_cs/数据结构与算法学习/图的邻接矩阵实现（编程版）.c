#include<stdio.h>
#include<stdlib.h>
//��Щ����Ĭ��Ϊ����ͼ����Ȩͼ 

//רҵ����Աһ�����Ѿ���һ��ͼ�ṹ�ˣ�ֻ����Ϊ�˷��㷴�����ã�Ū��һ���ṹ�� 
struct GNode{
	int nv;
	int ne;
	int gr[100][100];//��ʾ���Ƕ����붥��Ĺ�ϵ 
	char data[100];//��ʾ��������� 
};
typedef struct GNode* PtrToGNode;

typedef PtrToGNode MGraph;//����һ��ΪʲôҪͨ��һ���м�ֵ��ȷ����� 

typedef int Vertex;//רҵ����Ա��������������������������ݺ�һ��������

struct EdgeNode{
	Vertex v1,v2;
	int weight;//Ȩ�� 
};

typedef struct EdgeNode* PointToEdge;

typedef PointToEdge Edge; 

//��������ȴ���һ��ֻ��ʼ���˽���ͼ
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

//���������ڽ����ö����ͼ�в����
void CreateEdge(MGraph g,Edge e){
	g->gr[e->v1][e->v2]=e->weight;
	g->gr[e->v2][e->v1]=e->weight;
}

MGraph BuildGraph(){
	MGraph Graph;
	Edge E;//�ǵ��������� 
	Vertex VN;
	int EN;
	int i;
	scanf("%d",&VN);
	Graph=CreateGraph(VN);
	scanf("%d",&EN);
	E=(Edge)malloc(sizeof(struct EdgeNode));//�����ġ�����Ҫ�Ƚ���һ����������ݵĽ�㣬��������ǰ������ 
	for(i=0;i<EN;i++){
		scanf("%d%d%d",&E->v1,&E->v2,&E->weight);
		CreateEdge(Graph,E);
	}
	for(i=0;i<Graph->nv;i++){
		scanf("%c",&Graph->data[i]);//�����塣�����ʾ�����д�������� 
	}
	return Graph;
}
 
