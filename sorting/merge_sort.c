#include<stdio.h>
#include<stdlib.h>


void merge(int *arr, int lb, int mid, int ub);

void merge_sort(int *arr, int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub)/2;

        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int *arr, int lb, int mid, int ub)
{
    int n1 = mid - lb + 1;  //size of left sub array n1 = mid - left +1
    int n2 = ub - mid;      //size of right sub array n2 = right - mid
    int size = n1+n2;
    int *temp_array = (int *)calloc(size , sizeof(int));
    if(!temp_array)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }


    int i  = lb;          // for accessing left sub array
    int j = mid+1;      // for accessing right sub array
    int k = 0;          // for accessing temp array

    while(i<=mid && j<=ub)
    {
        if(arr[i] <= arr[j])
        {
            temp_array[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp_array[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        temp_array[k] = arr[i];
        k++;
        i++;
    }

    while(j <= ub)
    {
        temp_array[k] = arr[j];
        k++;
        j++;
    }

    for(int i=0; i<size; i++)
    {
        arr[lb + i] = temp_array[i];
    }

    free(temp_array);
}

int main()
{
    int n;
    printf("\n enter the size of the array : ");
    if( scanf("%d",&n) != 1 || n <= 0)
    {
        printf("\n Invalid input..exiting..!");
        exit(EXIT_FAILURE);
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if(!arr)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
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

    merge_sort(arr,0,n-1);
    printf("\n The sorted array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    free(arr);
    return 0;
}