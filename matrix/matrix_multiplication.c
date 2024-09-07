#include<stdio.h>
int main()
{
    int arr1[10][10],arr2[10][10],res[10][10]={0};
    int row1,col1,row2,col2;
    printf("\n enter the no.of rows and columns of matrix1 : ");
    scanf("%d %d",&row1,&col1);
    printf("\n enter the no.of rows and columns of matrix2 : ");
    scanf("%d %d",&row2,&col2);
    if(col1!=row2)
    {
        printf("\n the matrix multiplication is not possible");
        return -1;
    }
    printf("\n enter the values of matrix1 : \n");
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n enter the values of matrix2 : \n");
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\n the matrix1 is : \n");
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            printf("%d\t",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n the matrix2 is : \n");
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            for(int k=0;k<col1;k++)
            {
                res[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    printf("\n the resultant matrix is : \n");
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}