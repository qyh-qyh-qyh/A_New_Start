#include<stdio.h>
#include<stdlib.h>

//����һ��ʹ�þ�̬������������ 
typedef struct TreeNode{
	char val;
	int left;
	int right;
}Tree;

int main(){
	Tree T[10]={0};//�����ġ�ʮ���������� �ǵø�����������Ҫֱ�����ݽṹ 
	int check[10]={0};//����������ڼ��ÿ�����Ƿ�ָ�򣬿��Բ��ҵ����ڵ� 
	char cl,cr;//�����������ַ����ȱ�ʾ���� 
	int i;
	int n;
	int root; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
	   scanf("%c%c%c",&T[i].val,&cl,&cr);
	   if(cl!='-'){
	      T[i].left=cl-'0';//������� T
	      check[T[i].left]=1;
	   }
	   else	T[i].left=-1;
	   if(cr!='-'){
	      T[i].right=cr-'0';//������� T
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
