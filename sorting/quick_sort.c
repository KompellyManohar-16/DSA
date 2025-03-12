#include<stdio.h>
#include<stdlib.h>

int partitioning(int *arr, int lb, int ub);

void quick_sort(int *arr, int lb, int ub)    
{
    // lb : lower bound , ub : upper bound

    if( lb < ub )
    {
        int index = partitioning(arr,lb,ub);

            quick_sort(arr, lb, index-1);
            quick_sort(arr, index+1, ub);
    }
} 


int partitioning(int *arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    
    while(start < end)
    {
        while( start <= end && arr[start] <= pivot )
        {
            start++;
        }
        while( start <= end && arr[end] > pivot )
        {
            end--;
        }
        if(start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    arr[lb] = arr[end];
    arr[end] = pivot;

    return end;
}

int main()
{
    int n;
    printf("\n enter the no of elements in the array : ");
    scanf("%d",&n);

    int *arr=(int *)malloc(n * sizeof(int));
    printf("\n enter the elements in the array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n The array is : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    quick_sort(arr,0,n-1);
    printf("\n The sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}