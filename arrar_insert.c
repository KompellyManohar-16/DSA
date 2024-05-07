#include<stdio.h>
int main()
{
    int a[50],n,i,size,num,pos;
    printf("\n enter the size of the array : ");
    scanf("%d",&size);
    if(size>50)
    {
        printf("\n overflow not possible to enter more than 50 elements");
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
                printf("%d ",a[i]);
            }
            printf("\nenter the value to be inserted : ");
            scanf("%d",&num);
            printf("\n enter the position at which the value has to be inserted : ");
            scanf("%d",&pos);
            if(pos<=0||pos>size+1)
            {
                printf("\n not possible to insert because the position is out of the range");
            }
            else{
                for(i=size-1;i>=pos-1;i--)
                {
                    a[i+1]=a[i];
                }
                a[pos-1]=num;
                size++;
                printf("\n the new array is : ");
                for(i=0;i<size;i++)
                {
                    printf("%d ",a[i]);
                }
            }
    }
}