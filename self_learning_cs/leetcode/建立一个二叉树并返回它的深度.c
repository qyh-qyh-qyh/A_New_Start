#include<stdio.h>
typedef struct Node {
	char val;
	struct Node*left;
	struct Node*right;
}Tree ;
typedef Tree* TreeNode;
//创建一个树 ,按前序遍历输入 
void CreateTree(TreeNode*T){
	//printf("jinlaila");
	//if()
	char ch;
	scanf("%c",&ch);
	if(ch=='#'){
		T=NULL;
	}else {
		*T=(Tree*)malloc(sizeof(Tree));//给TreeNode赋予内存空间，第一个表示指向 
		(*T)->val=ch;//注意表示方法 
	
	    CreateTree(&(*T)->left);//注意表示方法 
	    CreateTree(&(*T)->right);
	   // printf("jinlaila");
	}
}
//计算树的深度,还是用递归计算 
int depth(TreeNode T){
	//printf("jinlaila");
	int m,n=0;
	if(T=NULL){
		return 0;
	}else{
	    //printf("%d\n",m);	
		m=depth(T->left);//这里是不是重新定义了一边m,n 
		n=depth(T->right);
		if(m>n){
			return m+1;
		}else{
			return n+1;
		}
	}
} 


int main(){
	TreeNode T;
	
	CreateTree(&T);
	int count=depth(T);
	printf("树的深度是%d",count); 
} 
