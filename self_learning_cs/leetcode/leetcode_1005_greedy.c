#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int arr[],int start,int mid,int end){//问题一，这是一个归并操作,四个参数
   // int len=strlen(arr);
    int result[10000];
    int k=0;
    int i=start;
    int j=mid+1;//问题二，归并中将数列分为两段进行归并操作
    while(i<=mid&&j<=end){
         if(arr[i]<arr[j]){
             result[k++]=arr[i++];
         }
         else{
             result[k++]=arr[j++];
         }
    }
    if(i==mid+1){
        while(j<=end){
            result[k++]=arr[j++];
        }
    }
    if(j==end+1){
        while(i<=mid){
            result[k++]=arr[i++];        
        }
    }//问题三，熟练这个操作,这里成功将所有的值按序拍好放入result数组中
    for(i=start,j=0;j<k;i++,j++){//问题四，将数据重新放回arr中，这里的参数都要注意一下
        arr[i]=result[j];
    }
}

void merge_sort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}


int largestSumAfterKNegations(int* nums, int numsSize, int k){
    merge_sort(nums,0,numsSize);//成功排好序
    int i=0;
    while(k>0){
        if(nums[i]<0){
            nums[i]=-nums[i];
            i++;
            k--;
        }
    }
    if(k>0){//表示还有操作数
        if(nums[i]<nums[i-1]){
           while(k>0){
               nums[i]=-nums[i];
               k--;
           }
        }
        else{
            while(k>0){
                nums[i-1]=-nums[i-1];
                k--;
            }
        }
    }
    int res=0;
    for(i=0;i<numsSize;i++){
        res+=nums[i];
    }
    return res;
}

int main(){
	int k;
	scanf("%d",&k);
	int nums[4];
	int i;
	for(i=0;i<4;i++){
		scanf("%d",&nums[i]);
	}
	int res=largestSumAfterKNegations(nums,4,3);
	printf("%d",res);
	return 0;
} 
