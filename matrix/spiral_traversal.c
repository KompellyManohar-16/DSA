#include<stdio.h>
int main()
{
    int arr[10][10],row,col;
    printf("\n enter the no.of rows and columns : ");
    scanf("%d %d",&row,&col);
    printf("\n enter the values of matrix : ");
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
    printf("\n spirally traversing the matrix : \n");
    int top=0,bottom=row-1;
    int left=0,right=col-1;
    while(top<=bottom && left<=right)
    {
        for(int i=top;i<=right;i++)
        {
            printf("%d\t",arr[top][i]);
        }
        top++;
        if(top<=bottom && left<=right)
        {
            for(int i=top;i<=bottom;i++)
            {
                printf("%d\t",arr[i][right]);
            }
            right--;
        }
        if(left<=right && top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                printf("%d\t",arr[bottom][i]);
            }
            bottom--;
        }
        if(top<=bottom && left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                printf("%d\t",arr[i][left]);
            }
            left++;
        }
    }
    return 0;
}