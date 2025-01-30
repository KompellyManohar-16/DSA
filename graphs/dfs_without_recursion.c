#include<stdio.h>
#define MAX 100

void dfs(int adj[MAX][MAX], int no_of_vertices, int start)
{
    int stack[MAX],top=-1;
    int visited[MAX]={0};

    stack[++top]=start;
    visited[start]=1;
    while(top>=0)
    {
        int current=stack[top--];
        printf("%d ",current);

        for(int i=no_of_vertices-1 ;i>=0; i--)
        {
            if(adj[current][i]==1 && !visited[i])
            {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int no_of_vertices,start;
    int adj[MAX][MAX];
    printf("\n enter no of vertices in the graph : ");
    scanf("%d",&no_of_vertices);
    if(no_of_vertices==0)
    {
        printf("\n The graph is empty");
        return 0;
    }
    printf("\n enter the adjacency matrix : ");
    for(int i=0;i<no_of_vertices;i++)
    {
        for(int j=0;j<no_of_vertices;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\n The adjacency matrix is : \n");
    for(int i=0;i<no_of_vertices;i++)
    {
        for(int j=0;j<no_of_vertices;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    printf("\n enter the starting index : ");
    scanf("%d",&start);

    printf("\n The DFS traversal is : ");
    dfs(adj,no_of_vertices,start);

    return 0;
}