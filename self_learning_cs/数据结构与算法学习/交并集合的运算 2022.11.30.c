#include<stdio.h>
#include<stdlib.h>

#define maxsize 100//注意一。注意define语句，别忘记怎么用了 

//并查集 
//问题二。一个集合中一个结点的表示 ,一个集合是一个结点数组 
typedef struct{
	int data;
	int parent;
}SetType;

//集合的查找 
int find(SetType s[maxsize],int num){
	int i;
	for(i=0;s[i].data!=num;i++){//疑惑：应该不用加上前面那个条件:i<maxsize 
		if(i>=maxsize){
			return -1;//没找到集合结点中有这个数,注意二。一个int型的函数，返回-1表示函数失败 
		}
	}
	for( ;s[i].parent>=0;i=s[i].parent);//注意三。循环体为空，函数依然执行，但是末尾要加分号
	return i;//在已经建好集合的情况下的，要是根结点的话就是返回自身,不是的话返回那个根结点 
}

//并集合，用到查找集合来确定根结点 
void Union(SetType s[maxsize],int num1,int num2){
	int root1,root2;
	root1=find(s,num1);
	root2=find(s,num2);
	if(root1!=root2){
		s[root2].parent=root1;
	}
} 
