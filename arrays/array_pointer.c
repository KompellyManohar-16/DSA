#include<stdio.h>
int main()
{
    int a[10],i,n;
    int *p;
    p=a;
    printf("\n enter the size of array : ");
    scanf("%d",&n); 
    for( i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        //scanf("%d",&a[i]);
        //scanf("%d",(a+i));
        //scanf("%d",(p+i));
    }
    printf("\n the entered array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(p+i));
        //printf("%d\t",*(a+i));
        //printf("%d\t",a[i]);
        //printf("%d\t",p[i]);
        //printf("%d\t",i[a]);
        //printf("%d\t",i[p]);
    }
    return 0;
}