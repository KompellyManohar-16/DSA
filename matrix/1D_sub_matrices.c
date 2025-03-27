#include<stdio.h>
#include<stdlib.h>

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
    printf("\n The sub arrays are : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            printf("(");
            for(int k=i; k<=j; k++)
            {
                printf("%d ",arr[k]);
                if(k<j) printf(",");
            }
            printf(")");
        }
        printf("\n");
    }

    return 0;
}