// GfG-Problem Link: https://bit.ly/3oekoir
// https://leetcode.com/problems/rotting-oranges/description/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node 
{
    int x,y,time;
};

int rotten_oranges(int **arr,int row, int col)
{
    struct node queue[MAX];
    int front=0,rear=0;
    int visited[row][col];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            visited[i][j]=0;
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==2)
            {
                queue[rear].x=i;
                queue[rear].y=j;
                queue[rear].time=0;
                rear++;
                visited[i][j]=1;
            }
        }
    }

    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    int time_count=0;

    while(front<rear)
    {
        struct node current=queue[front++];
        int current_row=current.x;
        int current_col=current.y;
        int current_time=current.time;

        if(current_time > time_count)
        {
            time_count=current_time;
        }

        for(int i=0; i<4; i++)
        {
            int new_row=current_row + delrow[i];
            int new_col=current_col + delcol[i];

            if( new_row>=0 && new_row < row && new_col>=0 && new_col < col && arr[new_row][new_col] == 1 && 
                                visited[new_row][new_col]!=1 )
            {
                arr[new_row][new_col]=2;
                queue[rear].x=new_row;
                queue[rear].y=new_col;
                queue[rear].time=current_time+1;
                rear++;
                visited[new_row][new_col]=1;
            }
        }
    }

    printf("\n The matrix after modification is : \n");
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
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==1)
            {
                return -1;
            }
        }
    }
    return time_count;
}

int main()
{
    int row,col;
    printf("\n enter the no of rows and columns in the matrix : ");
    scanf("%d %d",&row,&col);

    if(row <= 0 || col <= 0 || row > MAX || col > MAX)
    {
        printf("\n Invalid input ... exiting..!");
        return 0;
    }
    
    int **arr=(int **)malloc(row * sizeof(int *));
    for(int i=0;i<row;i++)
    {
        arr[i]=(int *)malloc(col * sizeof(int));
    }

    printf("\n enter the matrix : ");   // 2 represents rotten ... 1 represents fresh... 0 represents no fruit
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n The original matrix is : \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

   int result=rotten_oranges(arr,row,col);
   printf("\n The minimum time to rot all the fresh oranges is : %d",result);

   for(int i=0;i<row;i++)
   {
    free(arr[i]);
   }
   free(arr);
    
    return 0;
}