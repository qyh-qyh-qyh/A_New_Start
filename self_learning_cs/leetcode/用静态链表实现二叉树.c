#include<stdio.h>
#include<stdlib.h>

//问题一。使用静态链表来构建树 
typedef struct TreeNode{
	char val;
	int left;
	int right;
}Tree;

int main(){
	Tree T[10]={0};//问题四。十个结点的数组 记得给他起名，不要直接数据结构 
	int check[10]={0};//问题二。用于检查每个点是否被指向，可以查找到根节点 
	char cl,cr;//问题三。用字符串先表示左右 
	int i;
	int n;
	int root; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
	   scanf("%c%c%c",&T[i].val,&cl,&cr);
	   if(cl!='-'){
	      T[i].left=cl-'0';//变回数字 T
	      check[T[i].left]=1;
	   }
	   else	T[i].left=-1;
	   if(cr!='-'){
	      T[i].right=cr-'0';//变回数字 T
	      check[T[i].right]=1;
	   }
	   else	T[i].right=-1;
	   
	}
	for(i=0;i<n;i++){
		if(check[i]!=1){
			root=i;
			break;
		}	
	}
	printf("%d",root);
	return 0; 
}
