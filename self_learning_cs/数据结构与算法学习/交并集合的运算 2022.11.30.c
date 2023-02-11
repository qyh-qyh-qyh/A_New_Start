#include<stdio.h>
#include<stdlib.h>

#define maxsize 100//ע��һ��ע��define��䣬��������ô���� 

//���鼯 
//�������һ��������һ�����ı�ʾ ,һ��������һ��������� 
typedef struct{
	int data;
	int parent;
}SetType;

//���ϵĲ��� 
int find(SetType s[maxsize],int num){
	int i;
	for(i=0;s[i].data!=num;i++){//�ɻ�Ӧ�ò��ü���ǰ���Ǹ�����:i<maxsize 
		if(i>=maxsize){
			return -1;//û�ҵ����Ͻ�����������,ע�����һ��int�͵ĺ���������-1��ʾ����ʧ�� 
		}
	}
	for( ;s[i].parent>=0;i=s[i].parent);//ע������ѭ����Ϊ�գ�������Ȼִ�У�����ĩβҪ�ӷֺ�
	return i;//���Ѿ����ü��ϵ�����µģ�Ҫ�Ǹ����Ļ����Ƿ�������,���ǵĻ������Ǹ������ 
}

//�����ϣ��õ����Ҽ�����ȷ������� 
void Union(SetType s[maxsize],int num1,int num2){
	int root1,root2;
	root1=find(s,num1);
	root2=find(s,num2);
	if(root1!=root2){
		s[root2].parent=root1;
	}
} 
