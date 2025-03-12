#include<stdio.h>
#include<stdlib.h>

int *selection_sort(int *arr, int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
    {
        a[i]=arr[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int min = i;

        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        
        if(i != min)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    return a;
}

int main()
{
    int n;
    printf("\n enter the no of elements in the array : ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("\n enter the elements in the array is : ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n The array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    int *result = selection_sort(arr,n);
    printf("\n The sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    } 

    free(arr);
    free(result);
    return 0;
}