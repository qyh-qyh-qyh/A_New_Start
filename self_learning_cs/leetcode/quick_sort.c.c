#include <stdio.h>
// ��������һ�����ָ�������
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low; // ע���Ǵ�low��ʼ���������Ǵ��㿪ʼ
    int j;
    int temp;
    for (j = low; j < high; j++)
    { // ������high����Ϊÿ����������޲����ǳ���
        if (arr[j] < pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; // �ؼ�����i��¼��С��pivot��Ԫ�ظ�����ͬʱ,Ҳ��С��pivot��Ԫ��ȫ��Ū����ǰ��
            i++;
        }
    }
    temp = arr[high];
    arr[high] = arr[i];
    arr[i] = temp;
    return i;
}
// ��ʼ�ݹ�һ�������飬��������
void qsort(int arr[], int low, int high)
{
    if (low <= high)
    {
        int mid = partition(arr, low, high); // ����һֱû�䣬���Դ������Ļ���arr������Ҫ�޸ĵ��±�仯��
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

// void quicksort(int arr[],int len){
//	qsort(arr,0,len-C:\Users\86155\Desktop\�������ѧ����\������Ŀ����\��������.c1);
// }

// void quicksort(int arr[],int low,int)
int main()
{
    int n;
    scanf("%d", &n);
    int array[10];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    qsort(array, 0, n - 1);
    // quicksort(array,n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
