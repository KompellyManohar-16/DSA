#include<stdio.h>
int main()
{
    int a[10],i,n,num;
    printf("\nenter the size of an array: ");
    scanf("%d",&n);
    printf("\nenter the array elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n the entered array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nenter the num to insert : ");
    scanf("%d",&num);
    for(i=n-1;i>=0;i--)
    {
        a[i+1]=a[i];
    }
    a[0]=num;
    n++;
    printf("\nthe new array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}