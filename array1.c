#include<stdio.h>
int main()
{
    int a[5];
    int i,n;
    printf("\nenter the size of array: ");
    scanf("%d",&n);
    printf("\n enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n the entered elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nthe base address is : %d",a);
    printf("\nthe base address is : %u",a);
    printf("\n at index 2 : %d",2[a]);
    return 0;
}