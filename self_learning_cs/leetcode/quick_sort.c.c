#include <stdio.h>
// 将数组用一个数分隔在两边
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low; // 注意是从low开始遍历，不是从零开始
    int j;
    int temp;
    for (j = low; j < high; j++)
    { // 上限是high，因为每个数组的上限不都是长度
        if (arr[j] < pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; // 关键：用i记录了小于pivot的元素个数的同时,也把小于pivot的元素全部弄到了前面
            i++;
        }
    }
    temp = arr[high];
    arr[high] = arr[i];
    arr[i] = temp;
    return i;
}
// 开始递归一个个数组，分治它们
void qsort(int arr[], int low, int high)
{
    if (low <= high)
    {
        int mid = partition(arr, low, high); // 数组一直没变，所以传进来的还是arr，但是要修改的下标变化了
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

// void quicksort(int arr[],int len){
//	qsort(arr,0,len-C:\Users\86155\Desktop\计算机自学内容\力扣题目汇总\快速排序.c1);
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
