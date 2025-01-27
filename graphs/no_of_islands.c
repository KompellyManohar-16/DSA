// click this link for description
// https://leetcode.com/problems/number-of-islands/description/
// GfG Problem Link: https://bit.ly/3oT9Ndg

#include<stdio.h>
#include<stdlib.h>

int no_of_islands(int **grid, int row ,int col);
void recursion(int i, int j, int row, int col, int **grid);
int is_valid_dimensions(int i, int j, int row, int col, int **grid);

int no_of_islands(int **grid, int row ,int col)
{
    int count=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if( grid[i][j]==1 )
            {
                count++;
                recursion(i,j,row,col,grid);
            }
        }
    }
    return count;
}

void recursion(int i, int j, int row, int col, int **grid)
{
    grid[i][j]=0;

    if( is_valid_dimensions(i,j+1,row,col,grid))     //right
        recursion(i,j+1,row,col,grid);

    if( is_valid_dimensions(i,j-1,row,col,grid))     //left
        recursion(i,j-1,row,col,grid);

    if( is_valid_dimensions(i-1,j,row,col,grid))     //top
        recursion(i-1,j,row,col,grid);

    if( is_valid_dimensions(i+1,j,row,col,grid))     //bottom
        recursion(i+1,j,row,col,grid);

    if( is_valid_dimensions(i-1,j-1,row,col,grid))   //top-left
        recursion(i-1,j-1,row,col,grid);

    if( is_valid_dimensions(i-1,j+1,row,col,grid))   //top-right
        recursion(i-1,j+1,row,col,grid);

    if( is_valid_dimensions(i+1,j-1,row,col,grid))   //bottom-left
        recursion(i+1,j-1,row,col,grid);

    if( is_valid_dimensions(i+1,j+1,row,col,grid))   //bottom-right
        recursion(i+1,j+1,row,col,grid);
}

int is_valid_dimensions(int i, int j, int row, int col, int **grid)
{
    if( i>=0 && i<row && j>=0 && j<col && grid[i][j]==1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int row,col;
    printf("\n enter no of rows and columns in the grid : ");
    scanf("%d %d",&row,&col);

    if(row<=0 || col<=0)
    {
        printf("\n Invalid input.. exiting..1");
        return 0;
    }

    int **grid=(int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        grid[i]=(int*)malloc(col * sizeof(int));
    }

    printf("\n enter the grid values : ");  // 1-represents land and 0-represents water
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    int count=no_of_islands(grid,row,col);
    printf("\n The total no of islands are : %d",count);

    //free allocated memory
    for(int i=0;i<row;i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
