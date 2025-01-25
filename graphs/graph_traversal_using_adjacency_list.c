#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *create_node(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void create_adjacency_list(struct node *adj_list[], int edges[][2], int no_of_edges, int no_of_vertices)
{
    for(int i=0;i<no_of_edges;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        struct node *newnode=create_node(b);
        newnode->next=adj_list[a];
        adj_list[a]=newnode;

        newnode=create_node(a);
        newnode->next=adj_list[b];
        adj_list[b]=newnode;
    }
}

void print_adj_list(struct node *adj_list[],int no_of_vertices)
{
    for(int i=0;i<no_of_vertices;i++)
    {
        printf("\n %d : ",i);
        struct node *temp=adj_list[i];
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}

void bfs(struct node *adj_list[], int v, int start)
{
    int queue[v],front=0,rear=0;
    int visited[v];

    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }

    queue[rear++]=start;
    visited[start]=1;

    while(front < rear)
    {
        int current= queue[front++];
        printf("%d  ",current);

        struct node *temp=adj_list[current];
        while(temp!=NULL)
        {
            if( !visited[temp->data] )
            {
                queue[rear++]=temp->data;
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}

void dfs(struct node *adj_list[], int v, int start)
{
    int  stack[v],top=-1;
    int visited[v];
    
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }

    stack[++top]=start;

    while(top>=0)
    {
        int current=stack[top--];
        printf("%d  ",current);
        visited[current]=1;

        struct node *temp=adj_list[current];
        while(temp!=NULL)
        {
            if( !visited[temp->data] )
            {
                stack[++top]=temp->data;
            }
            temp=temp->next;
        }
    }
}

void free_list(struct node *adj_list[], int v)
{
    for(int i=0;i<v;i++)
    {
        struct node *temp=adj_list[i];
        while(temp!=NULL)
        {
            struct node *next=temp->next;
            free(temp);
            temp=next;
        }
    }
    for(int i=0;i<v;i++)
    {
        adj_list[i]=NULL;
    }
}

int main()
{
    int no_of_vertices,no_of_edges,start;

    printf("\n enter the no.of vertices : ");
    scanf("%d",&no_of_vertices);
    printf("\n enter the no of edges : ");
    scanf("%d",&no_of_edges);

    int edges[no_of_edges][2];

    printf("\n enter the edges : ");
    for(int i=0;i<no_of_edges;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&edges[i][j]);
        }
    }

    printf("\n The Edges are : \n");
    for(int i=0;i<no_of_edges;i++)
    {
            printf("\n %d - %d",edges[i][0],edges[i][1]);
    }

    struct node *adj_list[no_of_vertices];
    for(int i=0;i<no_of_vertices;i++)
    {
        adj_list[i]=NULL;
    }
    
    create_adjacency_list(adj_list,edges,no_of_edges,no_of_vertices);

    printf("\n The adjacency list is : \n");
    print_adj_list(adj_list,no_of_vertices);

    printf("\n enter the starting vertex : ");
    scanf("%d",&start);

    printf("\n The BFS traversal is : \n");
    bfs(adj_list,no_of_vertices,start);

    printf("\n The DFS traversal is : \n");
    dfs(adj_list,no_of_vertices,start);

    free_list(adj_list,no_of_vertices);

    return 0;
}