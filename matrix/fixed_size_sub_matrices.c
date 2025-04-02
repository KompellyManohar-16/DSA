#include<stdio.h>

int mean(int row, int col, int arr[row][col], int sub_row, int sub_col)
{
    int sum = 0;
    for(int i = 0; i <= row - sub_row; i++)
    {
        for(int j = 0; j <= col - sub_col; j++)
        {
            sum = 0;

            printf("\n The sub matrix at (%d,%d) is : \n",i,j);
            
            for(int a = i; a < i+sub_row; a++)
            {
                for(int b = j; b < j+sub_col; b++)
                {
                    printf("%d ",arr[a][b]);
                    
                    sum = sum + arr[a][b];
                }
                printf("\n");
            }

            int mean = sum/(sub_row * sub_col);
            if(mean == 7)
            {
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    int row,col,sub_row,sub_col;
    printf("\n enter the row and col size : ");
    scanf("%d %d",&row,&col);
    int arr[row][col];
    printf("\n enter the matrix elements : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n enter the sub_row and sub_col : ");
    scanf("%d %d",&sub_row,&sub_col);

    int result = mean(row,col,arr,sub_row,sub_col);
    if(result)
    {
        printf("\nTrue");
    }
    else
    {
        printf("\nFalse");
    }
    return 0;
}