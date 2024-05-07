#include<stdio.h>
int main()
{
    int a[10],i,size,num,pos;
    printf("\n enter the size of the array : ");
    scanf("%d",&size);
    printf("\n enter the array elements : ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nthe entered array elements are : ");
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nenter the new data to be inserted : ");
    scanf("%d",&num);
    printf("\nenter the position at which the data has to store : ");
    scanf("%d",&pos);
    a[size]=a[pos-1];
    a[pos-1]=num;
    size++;
    printf("\n the new array is : ");
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}