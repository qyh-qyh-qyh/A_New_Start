#include<stdio.h>
int head,data[100000],position[100000],idex;//�����ˣ�index�Ǹ��ڽ��������������׶������ 

//��̬�����������������ŵ㣬����ռ�Ŀռ�������
void init(){
    head=-1;//�������Ҫ�����Ͻ���ʱ���Ա�ʾ����Ľ���
    idex=0;
}
//�������ͷ�ڵ����Ԫ��
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
    //int head;//��ʾͷָ��
    //int index;//��ʾ��һ�����Բ����Ԫ�ص�λ��
    //int data[100000];//�������ݵ�����
    //int position[100000];//��ʾÿһ�����ݵ���һ�����ݵ�λ��
    init;
    int M,i;
    int x,k;
    scanf("%d",&M);//��ʾ��������
    int head=-1,index=0;
    char choice;
    for(i=0;i<M;i++){
    //char choice;//�����޶�ֻ�������Ǽ�����ĸ�������ϵͳ��������exist����
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
