#include<stdio.h>
int main()
{
    int a[10],i,n;
    printf("\n enter the size of array : ");
    scanf("%d",&n);
    printf("\nenter the array elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nthe array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}