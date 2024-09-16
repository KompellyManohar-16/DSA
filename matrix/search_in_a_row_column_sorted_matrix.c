#include<stdio.h>
int main()
{
    int arr[10][10];
    int row,col;
    int row_no=-1,found=0,num;
    printf("\n enter the no.of rows and columns : \n");
    scanf("%d %d",&row,&col);
    printf("\n enter the matrix values in sorted manner : \n");
    for(int k=0;k<row;k++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[k][j]);
        }
    }
    printf("\n the entered sorted matrix is : \n");
    for(int k=0;k<row;k++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d\t",arr[k][j]);
        }
        printf("\n");
    }
    printf("\n entered the value to search : ");
    scanf("%d",&num);
    for(int i=0;i<row;i++)
    {
        if(arr[i][0]<=num && arr[i][col-1]>=num)
        {
            row_no=i;
            break;
        }
    }
   if(row_no!=-1)
   {
        for(int j=0;j<col;j++)
        {
            if(arr[row_no][j]==num)
            {
                printf("\n the given number %d is found in the matrix at row : %d , at column : %d",num,row_no,j);
                found=1;
                break;
            }
        }
   }
   if(found==0)
   {
        printf("\n the given number %d is not found in the matrix",num);
   }
    return 0;
}