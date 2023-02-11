#include<stdio.h>
typedef struct Node {
	char val;
	struct Node*left;
	struct Node*right;
}Tree ;
typedef Tree* TreeNode;
//����һ���� ,��ǰ��������� 
void CreateTree(TreeNode*T){
	//printf("jinlaila");
	//if()
	char ch;
	scanf("%c",&ch);
	if(ch=='#'){
		T=NULL;
	}else {
		*T=(Tree*)malloc(sizeof(Tree));//��TreeNode�����ڴ�ռ䣬��һ����ʾָ�� 
		(*T)->val=ch;//ע���ʾ���� 
	
	    CreateTree(&(*T)->left);//ע���ʾ���� 
	    CreateTree(&(*T)->right);
	   // printf("jinlaila");
	}
}
//�����������,�����õݹ���� 
int depth(TreeNode T){
	//printf("jinlaila");
	int m,n=0;
	if(T=NULL){
		return 0;
	}else{
	    //printf("%d\n",m);	
		m=depth(T->left);//�����ǲ������¶�����һ��m,n 
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
	printf("���������%d",count); 
} 
