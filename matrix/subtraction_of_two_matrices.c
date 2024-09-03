#include<stdio.h>
int main()
{
    int arr1[10][10],arr2[10][10],arr3[10][10];
    int row1,row2,col1,col2;

    printf("\n enter the no.of rows and columns of arr1 : ");
    scanf("%d %d",&row1,&col1);
    printf("\n enter the no.of rows and columns of arr2 : ");
    scanf("%d %d",&row2,&col2);

    if(row1!=row2 || col1!=col2)
    {
        printf("\n the matrices dimensions are not equal so subtraction is not possible");
        return 1;
    }

    printf("\n enter the values of arr1 : ");
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    
    printf("\n enter the values of arr2 : ");
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }

    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            arr3[i][j]=arr1[i][j]-arr2[i][j];
        }
    }
    
    printf("\n the subtraction of two matrices is : \n");
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            printf("%d\t",arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}