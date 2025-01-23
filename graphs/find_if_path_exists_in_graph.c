//using BFS
#include <stdio.h>
#define MAX 100

void is_path_exists(int no_of_vertices, int edges[][2], int no_of_edges, int source, int destination)
{

    if(source == destination)
    {
        printf("\n The path exists for %d and %d",source,destination);
        return;
    }

    int adj_matrix[MAX][MAX]={0};

    for(int i=0;i<no_of_edges;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        adj_matrix[a][b]=1;
        adj_matrix[b][a]=1;
    }
    printf("\n The adjacenct matrix is : \n");
    for(int i=0;i<no_of_vertices;i++)
    {
        for(int j=0;j<no_of_vertices;j++)
        {
            printf("%d ",adj_matrix[i][j]);
        }
        printf("\n");
    }

    int queue[MAX],front=0,rear=0;
    int visited[MAX]={0};

    queue[rear++]=source;
    visited[source]=1;

    while(front < rear)
    {
        int current=queue[front++];
        
        if(current == destination)
        {
            printf("\n The paths exists for %d and %d",source,destination);
            return;
        }

        for(int i=0;i<no_of_vertices;i++)
        {
            if(adj_matrix[current][i] == 1 && !visited[i])
            {
                if(rear >= MAX)
                {
                    printf("\n Queue Overflow..");
                    return;
                }

                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
    printf("\n The path doesn't exists for %d and %d",source,destination);
}

int main()
{
    int no_of_vertices,no_of_edges;
    int source,destination;

    printf("\n enter the no.of vertices : ");
    scanf("%d",&no_of_vertices);
    printf("\n enter the no of edges : ");
    scanf("%d",&no_of_edges);

    int edges[no_of_edges][2]; // columns represents the two vertices that have an edge b/w them

    printf("\n enter the edges in the graph : ");
    for(int i=0;i<no_of_edges;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&edges[i][j]);
        }
    }

    printf("\n The edges are : \n");
    for(int i=0;i<no_of_edges;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",edges[i][j]);
        }
        printf("\n");
    }

    printf("\n enter the source and destination : ");
    scanf("%d %d",&source,&destination);

    is_path_exists(no_of_vertices, edges, no_of_edges, source, destination);

    return 0;
}