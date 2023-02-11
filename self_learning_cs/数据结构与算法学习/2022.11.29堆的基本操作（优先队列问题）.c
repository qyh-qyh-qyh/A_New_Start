#include<stdio.h>
#include<stdlib.h>

struct Heap{
	int*elements;
	int size;
	//int capacity;
};

typedef struct Heap* Mh;

//初始化一个最大堆
void init_heap(Mh h,int maxsize){
	h=malloc(sizeof(struct Heap));
	h->elements=malloc(maxsize*sizeof(int));//记得申请内存了 
	h->elements[0]=6666;//问题一。哨兵,确保后面插入不用再写i>1的条件 
	h->size=maxsize;
}
//插入一个元素并且还保持着堆的结构 （注意别漏了数组前面的指针号） 
void Insert(Mh h,int item){
	int i;
	i=(h->size)+1;
	//elements[i]=item;
	for( ;h->elements[i/2]<item;i/=2){//与item做的比较 ,最后才好确定item是在哪里 
		h->elements[i]=h->elements[i/2];//和上面一个注释统称为问题二。与item做对比才知道哪些结点要下顺
		 
	}h->elements[i]=item;
}

int Delete(Mh h,maxnum){
	int maxnum=h->elements[1];
	int parent,child;
	//问题三，从最后一个结点开始从上面开始筛选结点
	int temp=h->elements[(h->size)--];//既从最后一个结点开始，又能够减小size 
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
   
