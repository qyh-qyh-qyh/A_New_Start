#include<stdio.h>

void divide(int n){
    int i;
    for(i=2;i<=n/i;i++){//问题一，因为大于根号n的质数只会有一个，所以只用到n/i
        if(n%i==0){//问题二，表示i一定是一个质数，因为若i不是质数，那么一定有比它小的因子，则n早就把这个因子整除了
            int s=0;//计数
            while(n%i==0){
                n=n/i;//问题三，如何把这个整数关于一个质数的质因子个数全部找出
                s++;
            }
            printf("%d %d\n",i,s);
        }
    }
    if(n>1){//问题四，这里解决掉那个大于根号n的质数
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
