//给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。

//输出选择的点的最小数量。

//位于区间端点上的点也算作区间内。

//输入格式
//第一行包含整数 N，表示区间数。

//接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

//输出格式
//输出一个整数，表示所需的点的最小数量。

//数据范围
//1≤N≤105,
//?109≤ai≤bi≤109

#include<stdio.h>
//分治的办法（为快速排序服务） 
int partition(int arr[],int brr[],int low,int high){
    int pivot=arr[high];
    int i,temp;
    int position=low;
    for(i=low;i<high;i++){
        if(arr[i]<pivot){
            temp=arr[i];
            arr[i]=arr[position];
            arr[position]=temp;
            temp=brr[i];
            brr[i]=brr[position];
            brr[position]=temp;
            position++;
        }
    }temp=arr[high];
     arr[high]=arr[position];
     arr[position]=temp;
     temp=brr[high];
     brr[high]=brr[position];
     brr[position]=temp;
     return position;
}
//快速排序
void qsort(int arr[],int brr[],int left,int right){
    if(left<right){
        int mid=partition(arr,brr,left,right);
        partition(arr,brr,left,mid-1);
        partition(arr,brr,mid+1,right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[10000];//记录每个区间的前端点,但不是升序的，所以应该对a进行升序排列，并保证b的对应右区间和a的还是一样的
    int b[10000];//记录每个区间的后端点
    int i=0;
    int count=1;
    int num=0;//记录一共需要多少个点
    int j=1;
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    //对a进行升序排列，尝试一下快速排序
    qsort(a,b,0,n-1);
   // printf("%d",a[n-1]);//调试说明已经升序排好
    
    i=0;//不修改进入不了循环（在while循环中重要） 
    while(i<n){
        
        printf("%d\n",b[i]);
        while(b[i]>a[i+j]){//这里是问题所在，到底该怎么设置条件（很重要很重要） 
           j++;
           count++;
        }
        i+=count;
        //printf("%d\n",count);//调试出这里应该是循环错了
        j=1;
        count=1;
        num++;
        //printf("%d\n",num);
    }printf("%d",num);
    return 0;
}
