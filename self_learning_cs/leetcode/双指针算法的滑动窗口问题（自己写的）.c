#include<stdio.h>
//子串问题用滑动窗口解决
int main(){
    int n;
    scanf("%d",&n);
    int array[100000];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int left=0,right=1;//设置左右窗口
    int max=1;
    int count=0;
    for(right=1;right<n;right++){
        for(i=left;i<right;i++){
            if(array[right]==array[i]){
                if(right-left>max){
                    max=right-left;
                    //printf("%d\n",max);
                }left=i+1;
                //printf("%d\n",left);
                //count=1;
                break;
            }

        }if(right==n-1){
            if(right-left+1>max){
                max=right-left+1;
            }
        }
    }
    printf("%d",max);
     return 0;
}
