// The array must be sorted then only the binary search is applicable

#include<stdio.h>
#include<stdlib.h>

int binary_search(int *arr, int n, int data)
{
    int left = 0;
    int right = n-1;

    while(left <= right)
    {
        int mid = ( left + right ) / 2;

        if(arr[mid] == data)
        {
            return mid;
        }
        else if(arr[mid] < data)
        {
            left = mid + 1;
        }
        else if(arr[mid] > data)
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("\n enter the no of elements in the array : ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n * sizeof(int));
    printf("\n enter the elements of the array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n The array is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    int data;
    printf("\n enter the data to search : ");
    scanf("%d",&data);

    int index = binary_search(arr,n,data);
    if(index >= 0)
    {
        printf("\n The data %d is found in the array at %d",data,index);
    }
    else
    {
        printf("\n The data %d is not found in the array",data);
    }

    free(arr);
    return 0;
}