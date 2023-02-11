#include<stdio.h>
#include<stdlib.h>

struct Heap{
	int*elements;
	int size;
	//int capacity;
};

typedef struct Heap* Mh;

//��ʼ��һ������
void init_heap(Mh h,int maxsize){
	h=malloc(sizeof(struct Heap));
	h->elements=malloc(maxsize*sizeof(int));//�ǵ������ڴ��� 
	h->elements[0]=6666;//����һ���ڱ�,ȷ��������벻����дi>1������ 
	h->size=maxsize;
}
//����һ��Ԫ�ز��һ������ŶѵĽṹ ��ע���©������ǰ���ָ��ţ� 
void Insert(Mh h,int item){
	int i;
	i=(h->size)+1;
	//elements[i]=item;
	for( ;h->elements[i/2]<item;i/=2){//��item���ıȽ� ,���ź�ȷ��item�������� 
		h->elements[i]=h->elements[i/2];//������һ��ע��ͳ��Ϊ���������item���ԱȲ�֪����Щ���Ҫ��˳
		 
	}h->elements[i]=item;
}

int Delete(Mh h,maxnum){
	int maxnum=h->elements[1];
	int parent,child;
	//�������������һ����㿪ʼ�����濪ʼɸѡ���
	int temp=h->elements[(h->size)--];//�ȴ����һ����㿪ʼ�����ܹ���Сsize 
	for(parent=1;parent*2<=h->size;parent=child){
		child=parent*2;
		if((child+1<=h->size)&&h->elements[child]<h->elements[child+1]){
			child++;
		}
		if(temp>=h->elements[child]){
			break;
		}
		else{
			h->elements[parent]=h->elements[child];		
		} 
	}
	h->elements[parent]=temp;
	return maxnum; 
}
   
