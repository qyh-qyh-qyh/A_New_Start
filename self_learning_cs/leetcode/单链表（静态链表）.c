#include<stdio.h>
int head,data[100000],position[100000],idex;//被坑了，index是个内建函数，不能轻易定义变量 

//静态链表兼具链表和数组的优点，但是占的空间比链表大
void init(){
    head=-1;//这个很重要，不断进行时可以表示链表的结束
    idex=0;
}
//在链表的头节点插入元素
void add_to_head(int x){
    data[idex]=x;
    position[idex]=head;
    head=idex;
    idex++;
}

void add(int x,int k){
    data[idex]=x;
    position[idex]=position[k];
    position[k]=idex;
    idex++;
}

void shanchu(int k){
    position[k]=position[position[k]];
}

int main(){
    //int head;//表示头指针
    //int index;//表示下一个可以插入的元素的位置
    //int data[100000];//储存数据的数组
    //int position[100000];//表示每一个数据的下一个数据的位置
    init;
    int M,i;
    int x,k;
    scanf("%d",&M);//表示操作次数
    int head=-1,index=0;
    char choice;
    for(i=0;i<M;i++){
    //char choice;//采用限定只能输入那几个字母，像财务系统那样定个exist变量
    scanf("%c",&choice);
    if(choice=='H'){
        scanf("%d",&x);
        add_to_head(x);
    }
    else if(choice=='I'){
        scanf("%d%d",&k,&x);
        add(x,k);
    }
    else{
        scanf("%d",&k);
        shanchu(k);
    }
  }
  for(i=head;position[i]!=-1;i=position[i]){
      printf("%d ",data[i]);
  }
  return 0;
}
