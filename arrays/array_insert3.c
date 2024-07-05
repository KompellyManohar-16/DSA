#include<stdio.h>
int main()
{
    int a[10],i,n,num;
    printf("\nenter the size of the array: ");
    scanf("%d",&n);
    printf("\nenter the array elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n the entered array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n enter the data to be inserted : ");
    scanf("%d",&num);
    a[n]=num;
    n++;
    printf("\n the new array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
return 0;
}