// GfG-Problem Link: https://bit.ly/3QLxjET
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX
#define MAX 100

int shortest_path(int **grid, int row, int col, int *src, int *dest);

int shortest_path(int **grid, int row, int col, int *src, int *dest)
{
    if( grid[dest[0]][dest[1]] == 0 || grid[src[0]][src[1]] == 0)     return -1;

    if(src[0] == dest[0] && src[1] == dest[1])   return 0;

    int **dist = (int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        dist[i] = (int *)malloc(col * sizeof(int));
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            dist[i][j]=INFINITY;
        }
    }

    struct queue_node
    {
        int dist;
        int row;
        int col;
    };
    struct queue_node queue[MAX];
    int front = 0, rear = 0;

    queue[rear].dist = 0;
    queue[rear].row = src[0];
    queue[rear].col = src[1];
    rear++;

    dist[src[0]][src[1]] = 0;

    int del_row[]={-1,0,1,0};
    int del_col[]={0,1,0,-1};

    while(front < rear)
    {
        int current_dist = queue[front].dist;
        int current_row = queue[front].row;
        int current_col = queue[front].col;
        front++;

        printf("\nThe cell is : %d %d %d\n",current_dist,current_row,current_col);

        for(int i=0;i<4;i++)
        {
            int nrow = current_row + del_row[i];
            int ncol = current_col + del_col[i];

            if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col)
            {
               if( grid[nrow][ncol] == 1)
               {
                    if(nrow == dest[0] && ncol == dest[1])
                    {
                        for(int i=0;i<row;i++)
                        {
                            free(dist[i]);
                        }
                        free(dist);
                        return current_dist+1;
                    }

                    int new_dist = current_dist + 1;
                    if( new_dist < dist[nrow][ncol] )
                    {
                        dist[nrow][ncol] = new_dist;
                        queue[rear].dist = new_dist;
                        queue[rear].row = nrow;
                        queue[rear].col = ncol;
                        rear++;
                    }
               }
            }
        }
    }
    for(int i=0;i<row;i++)
    {
        free(dist[i]);
    }
    free(dist);
    return -1;
}



int main()
{
    int row,col;
    printf("\n enter the no of rows and columns in the grid : ");
    scanf("%d %d",&row,&col);

    int **grid = (int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        grid[i]=(int *)malloc(col * sizeof(int));
    }

    printf("\n enter the values of the grid : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    printf("\n The entered grid is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }

    int *src = (int *)malloc(2 * sizeof(int));
    int *dest = (int *)malloc(2 * sizeof (int));

    printf("\n enter the source cell : ");
    scanf("%d %d",&src[0],&src[1]);

    printf("\n enter the destination cell : ");
    scanf("%d %d",&dest[0],&dest[1]);

    printf("\n The source and destination is : %d %d %d %d",src[0],src[1],dest[0],dest[1]);

    int result = shortest_path(grid,row,col,src,dest);

    printf("\n\n The shortes path is : %d",result);

    for(int i=0;i<row;i++)
    {
        free(grid[i]);
    }
    free(grid);
    free(src);
    free(dest);

    return 0;
}