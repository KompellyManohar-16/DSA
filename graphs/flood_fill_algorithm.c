// click this link for description
// GfG Problem Link: https://bit.ly/3bxY94d
// https://leetcode.com/problems/flood-fill/


#include<stdio.h>
#include<stdlib.h>

void flood_fill(int **arr, int row, int col, int i, int j, int new_color);
void dfs(int **arr, int row, int col, int i, int j, int old_color, int new_color);
int is_valid(int **arr, int row, int col, int i, int j, int old_color);

void flood_fill(int **arr, int row, int col, int i, int j, int new_color)
{
    if(arr[i][j]==new_color)
    {
        return; //is the new color is same the source color
    }
    int old_color=arr[i][j];
    
    dfs(arr,row,col,i,j,old_color,new_color);

}

void dfs(int **arr, int row, int col, int i, int j, int old_color, int new_color)
{
    arr[i][j]=new_color;

    if( is_valid(arr,row,col,i,j+1,old_color) )
        dfs(arr,row,col,i,j+1,old_color,new_color);

    if( is_valid(arr,row,col,i,j-1,old_color) )
        dfs(arr,row,col,i,j-1,old_color,new_color);

    if( is_valid(arr,row,col,i+1,j,old_color) )
        dfs(arr,row,col,i+1,j,old_color,new_color);

     if( is_valid(arr,row,col,i-1,j,old_color) )
        dfs(arr,row,col,i-1,j,old_color,new_color);
}

int is_valid(int **arr, int row, int col, int i, int j, int old_color)
{
    if( i>=0 && i<row && j>=0 && j<col && arr[i][j]==old_color)
        return 1;
    return 0;
}

int main()
{
    int row,col,new_color,sr,sc;
    printf("\n enter the no of rows and columns in the image : ");
    scanf("%d %d",&row,&col);

    int **arr=(int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        arr[i]=(int *)malloc(col * sizeof(int));
    }

    printf("\n enter the values of the image : ");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n The Original image is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n enter the new color : ");
    scanf("%d",&new_color);
    printf("\n enter the source row and source column : ");
    scanf("%d %d",&sr,&sc);

    flood_fill(arr,row,col,sr,sc,new_color);

    printf("\n After changing the color the image is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<row;i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}