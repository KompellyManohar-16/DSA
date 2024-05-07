#include<stdio.h>
int main()
{
    int a[10],i,size,pos,del;
    printf("\n enter the size of array : ");
    scanf("%d",&size);
    if(size>10)
    {
        printf("\n overflow ");
    }
    else
    {
        printf("\nenter the array elements : ");
        for(i=0;i<size;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("\n the entered array is : ");
        for(i=0;i<size;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\nenter the position to delete : ");
        scanf("%d",&pos);
        if(pos<=0||pos>size)
        {
            printf("\n overflow enter correct position");
        }
        else{
            del=a[pos-1];
            for(i=pos-1;i<size-1;i++)
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
    }
    return 0;
}