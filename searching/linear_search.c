#include<stdio.h>
#include<stdlib.h>

int linear_search(int *arr, int n, int data)
{
    for(int i=0;i<n;i++)
    {
        if( arr[i] == data )
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("\n no of elements in the array : ");
    scanf("%d",&n);
    int *arr=(int *)malloc(n * sizeof(int));
    printf("\n enter the elements of the array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int data;
    printf("\n enter the data to search : ");
    scanf("%d",&data);

    int index = linear_search(arr,n,data);
    if(index >= 0)
    {
        printf("\n The data is found at the index : %d",index);
    }
    else
    {
        printf("\n The data is not found in the array");
    }
    return 0;
}