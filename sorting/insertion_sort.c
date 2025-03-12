#include<stdio.h>
#include<stdlib.h>

int *insertion_sort(int *arr, int n)
{
    int *a = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
    {
        a[i]=arr[i];
    }

    for(int i=1; i<n; i++)
    {
        int k=i;
        int temp = a[i];

        for(int j = i-1; j >= 0; j--)
        {
            if( a[j] > temp )
            {
                a[k] = a[j];
                k--;
            }
            else
            {
                break;
            }
        }
        a[k] = temp;
    }
    return a;
}

int main()
{
    int n;
    printf("\n enter the no of elements in the array : ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("\n enter the elements of the array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n The array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    int *result = insertion_sort(arr,n);
    printf("\n The sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }

    free(arr);
    free(result);

    return 0;
}