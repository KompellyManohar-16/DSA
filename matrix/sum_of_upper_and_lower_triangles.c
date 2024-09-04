#include<stdio.h>
int main()
{
    int arr[10][10],upper_sum=0,lower_sum=0;
    int row,col;
    printf("\n enter the no.of rows and columns : ");
    scanf("%d %d",&row,&col);
    if(row!=col)
    {
        printf("\n it is not a square matrix");
        return -1;
    }
    printf("\n enter the values of matrix : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
        {
            lower_sum+=arr[i][j];
        }
    }
    // for(int i=0;i<row;i++)                         
    // {                                                 
    //     for(int j=i;j<col;j++)
    //     {
    //         upper_sum+=arr[i][j];
    //     }
    // }
    for(int i=0;i<row;i++)                         
    {                                                 
        for(int j=row-1;j>=i;j--)
        {
            upper_sum+=arr[i][j];
        }
    }
    printf("\n the sum of uppper triangle is : %d \n the sum of lower triangle is : %d",upper_sum,lower_sum);
    return 0;
}