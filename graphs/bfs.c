#include<stdio.h>
#define MAX 100



void bfs(int adj[MAX][MAX], int no_of_vertices, int start)
{

    int visited[MAX]={0};
    int queue[MAX], rear=0, front=0;

    queue[rear++]=start;
    visited[start]=1;

    while(front < rear)
    {
        int current = queue[front++];
        printf("%d ",current);

        for(int i=0;i<no_of_vertices;i++)
        {
            if( adj[current][i] == 1 && visited[i]!=1 )
            {
                if(rear >= MAX)
                {
                    printf("\n Queue overflow..");
                    return;
                }   

                queue[rear++]=i;
                visited[i]=1;
                
            }
        }
    }
}

int main()
{
    int no_of_vertices, start;
    int adj[MAX][MAX]={0};

    printf("\n enter the no.of vertices in the graph : ");
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



    printf("\n The bfs traversal is : ");
    bfs(adj, no_of_vertices, start);
    return 0;
}