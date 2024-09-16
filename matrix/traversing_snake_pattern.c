#include<stdio.h>
 
int main()
{
    int arr[10][10],row,col;
    printf("\n enter the no.of rows and columns : ");
    scanf("%d %d",&row,&col);
    printf("\n enter the values of the matrix : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n the matrix is : \n");
    for(int j=0;j<row;j++)
    {
        for(int k=0;k<col;k++)
        {
            printf("%d\t",arr[j][k]);
        }
        printf("\n");
    }
    printf("\n the elements in snake pattern : \n");
    for(int i=0;i<row;i++)
    {
        if(i%2==0)
        {
                for(int j=0;j<col;j++)
                {
                    printf("%d\t",arr[i][j]);
                }
        }
        else
        {
                for(int j=col-1;j>=0;j--)
                {
                    printf("%d\t",arr[i][j]);
                }
        }
    }
    return 0;
}