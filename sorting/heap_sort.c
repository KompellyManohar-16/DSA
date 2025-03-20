#include<stdio.h>

void heap_sort(int *arr, int n);
void heapify(int *arr, int n, int i);
void swap(int *a, int *b);

void heap_sort(int *arr, int n)
{
    for(int i=n/2-1; i>=0; i--)       //starting with the last non leaf node ie n/2-1 
    {
        heapify(arr,n,i);
    }

    printf("\n The Max heap is : ");
    for(int i=0; i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    for(int i=n-1; i>0; i--)
    {
       swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr,n,largest);
    }
}

int main()
{
    int n;
    printf("\n enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\n enter the array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n The array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    heap_sort(arr,n);
    printf("\n The sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}