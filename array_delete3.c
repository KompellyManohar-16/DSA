#include<stdio.h>
int main()
{
    int a[10],n,i,del,size;
    printf("\n enter the size of the array : ");
    scanf("%d",&size);
    if(size>10)
    {
        printf("\n overflow not possible to enter more than 10 elements");
    }
    else
    {
            printf("\nenter the array elements : ");
            for(i=0;i<size;i++)
            {
                scanf("%d",&a[i]);
            }
            printf("\nthe entered elements are : ");
            for(i=0;i<size;i++)
            {
                printf("%d\t",a[i]);
            }
            del=a[0];
            for(i=0;i<size-1;i++)
            {
                a[i]=a[i+1];
            }
            size--;
            printf("\n the new array is : ");
            for(i=0;i<size;i++)
            {
                printf("%d\t",a[i]);
            }
            printf("\n the deleted element is : %d",del);
    }
    return 0;
}