#include<stdio.h>
#define MAX 100

int cycle_detection_bfs(int edges[][2], int no_of_edges, int no_of_vertices)
{
    int adj_matrix[MAX][MAX]={0};

    for(int i=0;i<no_of_edges;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        adj_matrix[a][b]=1;
        adj_matrix[b][a]=1;
    }

    int queue[MAX],front=0,rear=0;
    int visited[no_of_vertices];
    int parent[no_of_vertices];

    for(int i=0;i<no_of_vertices;i++)
    {
        visited[i]=0;

        parent[i]=-1;
    }

    for(int start=0; start < no_of_vertices; start++)
    {
        if( !visited[start] )
        {
            front=rear=0;
            queue[rear++]=start;
            visited[start]=1;

            while(front < rear)
            {
                int current = queue[front++];
                for(int i=0;i<no_of_vertices;i++)
                {
                    if( adj_matrix[current][i]==1 && !visited[i] )
                    {
                        queue[rear++]=i;
                        visited[i]=1;
                        parent[i]=current;
                    }
                    else if(adj_matrix[current][i] ==1 && visited[i]==1 && parent[current] != i)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int cycle_detection_dfs(int edges[][2], int no_of_edges, int no_of_vertices)
{
    int adj_matrix[MAX][MAX]={0};
    for(int i=0;i<no_of_edges;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        adj_matrix[a][b]=1;
        adj_matrix[b][a]=1;
    }

    int stack[MAX],top=-1;
    int visited[no_of_vertices];
    int parent[no_of_vertices];

    for(int i=0;i<no_of_vertices;i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }

    for(int start=0; start < no_of_vertices; start++)
    {
        if( !visited[start] )
        {
            top=-1;

            stack[++top]=start;

            while(top>=0)
            {
                int current=stack[top--];
                visited[current]=1;

                for(int i=0;i<no_of_vertices;i++)
                {
                    if( adj_matrix[current][i] == 1 && !visited[i] )
                    {
                        stack[++top]=i;
                        parent[i]=current;
                    }
                    else if( adj_matrix[current][i] == 1 && visited[i]==1 && parent[current] != i)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    int no_of_vertices,no_of_edges;

    printf("\n enter the no of vertices : ");
    scanf("%d",&no_of_vertices);
    if(no_of_vertices <= 0 || no_of_vertices > MAX)
    {
        printf("\n Invalid input.. exiting..!");
        return 0;
    }
    printf("\n enter the no of edges : ");
    scanf("%d",&no_of_edges);
    if(no_of_edges <=0)
    {
        printf("\n Invalid input.. exiting..!");
        return 0;
    }

    int edges[no_of_edges][2];

    printf("\n enter the edges in the graph: ");
    for(int i=0;i<no_of_edges;i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d",&edges[i][j]);
        }
    }

    printf("\n The edges are : \n");
    for(int i=0;i<no_of_edges;i++)
    {
        printf("\n %d - %d",edges[i][0],edges[i][1]);
    }

    if( cycle_detection_bfs(edges,no_of_edges,no_of_vertices) )
    {
        printf("\n The graph contains cycle");
    }
    else
    {
        printf("\n The graph doesn't contains cycle");
    }

    if( cycle_detection_dfs(edges,no_of_edges,no_of_vertices))
    {
        printf("\n The graph contains cylce");
    }
    else
    {
        printf("\n The graph doesn't contains cycle");
    }

    return 0;
}