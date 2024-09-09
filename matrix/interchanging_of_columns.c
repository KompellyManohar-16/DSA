#include<stdio.h>
int main()
{
    int arr[10][10];
    int row,col;
    printf("\n enter the no.of rows and columns : ");
    scanf("%d %d",&row,&col);
    printf("\n enter the matrix values : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n the entered matrix is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col/2;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[i][col-j-1];
            arr[i][col-j-1]=temp;
        }
    }
    printf("\n the matrix after the interchanging of columns : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}