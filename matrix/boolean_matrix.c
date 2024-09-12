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
    int row_no[row]={0},col_no[col]={0};
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==1)
            {
                row_no[i]=1;
                col_no[j]=1;
            }
        }
    }
    for(int i=0;i<row;i++)
    {
        if(row_no[i]==1)
        {
            for(int j=0;j<col;j++)
            {
                arr[i][j]=1;
            }
        }
    }
    for(int j=0;j<col;j++)
    {
        if(col_no[j]==1)
        {
            for(int i=0;i<row;i++)
            {
                arr[i][j]=1;
            }
        }
    }
    printf("\n matrix after modification is : \n");
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