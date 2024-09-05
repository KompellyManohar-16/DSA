#include<stdio.h>
int main()
{
    int arr1[10][10],arr2[10][10],row,col;
    printf("\n enter the rows and columns : ");
    scanf("%d %d",&row,&col);
    printf("\n enter the matrix elements : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n the matrix is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",arr1[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr2[j][i]=arr1[i][j];
        }
    }

    // when we transpose a matrix then the rows and cols are swapped.
    printf("\n the transpose matrix is : \n");
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}