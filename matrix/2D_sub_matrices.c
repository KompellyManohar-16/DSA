#include<stdio.h>
int main()
{
    int row,col;
    printf("\n enter no.of rows and no.of columns : ");
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


    for(int i1=0; i1<row; i1++)
    {
        for(int j1=0; j1<col;  j1++)
        {
            for(int i2=i1; i2<row; i2++)
            {
                for(int j2=j1; j2<col; j2++)
                {
                    printf("\n The sub array from (%d,%d) to (%d,%d) is : \n",i1,j1,i2,j2);
                    printf("----------------------\n");
                    for(int i=i1; i<=i2; i++)
                    {
                        for(int j=j1; j<=j2; j++)
                        {
                            printf("%d ",arr[i][j]);
                        }
                        printf("\n");
                    }
                    printf("----------------------\n");
                }
            }
        }
    }

    
    return 0;
}