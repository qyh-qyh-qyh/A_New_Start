#include<stdio.h>

void divide(int n){
    int i;
    for(i=2;i<=n/i;i++){//����һ����Ϊ���ڸ���n������ֻ����һ��������ֻ�õ�n/i
        if(n%i==0){//���������ʾiһ����һ����������Ϊ��i������������ôһ���б���С�����ӣ���n��Ͱ��������������
            int s=0;//����
            while(n%i==0){
                n=n/i;//����������ΰ������������һ�������������Ӹ���ȫ���ҳ�
                s++;
            }
            printf("%d %d\n",i,s);
        }
    }
    if(n>1){//�����ģ����������Ǹ����ڸ���n������
        printf("%d %d\n",n,1);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int num;
    int i;
    for(i=0;i<n;i++){
       scanf("%d",&num);
       divide(num);
    }
    return 0;
}
