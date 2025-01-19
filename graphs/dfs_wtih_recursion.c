#include<stdio.h>
#define MAX 100

void dfs(int adj[MAX][MAX], int no_of_vertices, int start, int visited[MAX])
{
   
   visited[start]=1;
   printf("%d ",start);

   for(int i=0;i<no_of_vertices;i++)
   {
        if(adj[start][i]==1 && !visited[i])
        {
            dfs(adj,no_of_vertices,i,visited);
        }
   }
}

int main()
{
    int no_of_vertices, start;
    int adj[MAX][MAX];

    int visited[MAX]={0};
    int stack[MAX],top=-1;

    printf("\n enter the no of vertices in the graph : ");
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
    printf("\n The entered adjacency matrix : ");
    for(int i=0;i<no_of_vertices;i++)
    {
        for(int j=0;j<no_of_vertices;j++)
        {
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }

    printf("\n enter the starting index : ");
    scanf("%d",&start);

    printf("\n The DFS traversal is : ");
    dfs(adj, no_of_vertices, start, visited);

    return 0;
}