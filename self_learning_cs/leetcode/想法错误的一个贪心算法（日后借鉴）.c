//���� N �������� [ai,bi]��������������ѡ�����ٵĵ㣬ʹ��ÿ�����������ٰ���һ��ѡ���ĵ㡣

//���ѡ��ĵ����С������

//λ������˵��ϵĵ�Ҳ���������ڡ�

//�����ʽ
//��һ�а������� N����ʾ��������

//������ N �У�ÿ�а����������� ai,bi����ʾһ������������˵㡣

//�����ʽ
//���һ����������ʾ����ĵ����С������

//���ݷ�Χ
//1��N��105,
//?109��ai��bi��109

#include<stdio.h>
//���εİ취��Ϊ����������� 
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
//��������
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
    int a[10000];//��¼ÿ�������ǰ�˵�,����������ģ�����Ӧ�ö�a�����������У�����֤b�Ķ�Ӧ�������a�Ļ���һ����
    int b[10000];//��¼ÿ������ĺ�˵�
    int i=0;
    int count=1;
    int num=0;//��¼һ����Ҫ���ٸ���
    int j=1;
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    //��a�����������У�����һ�¿�������
    qsort(a,b,0,n-1);
   // printf("%d",a[n-1]);//����˵���Ѿ������ź�
    
    i=0;//���޸Ľ��벻��ѭ������whileѭ������Ҫ�� 
    while(i<n){
        
        printf("%d\n",b[i]);
        while(b[i]>a[i+j]){//�������������ڣ����׸���ô��������������Ҫ����Ҫ�� 
           j++;
           count++;
        }
        i+=count;
        //printf("%d\n",count);//���Գ�����Ӧ����ѭ������
        j=1;
        count=1;
        num++;
        //printf("%d\n",num);
    }printf("%d",num);
    return 0;
}
