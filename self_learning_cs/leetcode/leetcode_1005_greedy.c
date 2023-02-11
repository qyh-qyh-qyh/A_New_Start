#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int arr[],int start,int mid,int end){//����һ������һ���鲢����,�ĸ�����
   // int len=strlen(arr);
    int result[10000];
    int k=0;
    int i=start;
    int j=mid+1;//��������鲢�н����з�Ϊ���ν��й鲢����
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
    }//�������������������,����ɹ������е�ֵ�����ĺ÷���result������
    for(i=start,j=0;j<k;i++,j++){//�����ģ����������·Ż�arr�У�����Ĳ�����Ҫע��һ��
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
    merge_sort(nums,0,numsSize);//�ɹ��ź���
    int i=0;
    while(k>0){
        if(nums[i]<0){
            nums[i]=-nums[i];
            i++;
            k--;
        }
    }
    if(k>0){//��ʾ���в�����
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
