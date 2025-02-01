// GfG-Problem Link: https://bit.ly/3PvBfsm

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node 
{
    int data;
    struct node *next;
};

struct graph
{
    struct node *head[MAX];
};


int *topological_sort(struct graph *g, int vertices)
{
    int *result=(int *)malloc(vertices * sizeof(int)); //the resultant topological sort that we should return
    int r=0;

    int *queue=(int *)malloc(vertices * sizeof(int));
    int front=0,rear=0;

    int *in_degree=(int *)malloc(vertices * sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        in_degree[i]=0;
    }

    for(int i=0;i<vertices;i++)         // this is for calculating the in degree for each vertex
    {
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            int data=temp->data;
            in_degree[data]++;
            temp=temp->next;
        }
    }

    printf("\n The in_degree of each vertex is : \n");
    for(int i=0;i<vertices;i++)
    {
        printf("%d ",in_degree[i]);
    }

    for(int i=0;i<vertices;i++)
    {
        if( in_degree[i] == 0 )
        {
            queue[rear++]=i;
        }
    }
    
    while(front < rear)
    {
        int current=queue[front++];
        result[r++]=current;
        
        struct node *temp=g->head[current];
        while(temp!=NULL)
        {
            in_degree[temp->data]--;

            if( in_degree[temp->data] == 0 )
            {
                queue[rear++]=temp->data;
            }

            temp=temp->next;
        }
    }
    
    free(queue);
    free(in_degree);

    if(r != vertices)
    {
        printf("\n cycle detected in the graph .. Topological sort is not possible..exiting...!");
        free(result);
        return NULL;
    }

    return result;
}

void add_edge(struct graph *g, int src, int dest)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->data=dest;
    newnode->next=g->head[src];
    g->head[src]=newnode;
}


int main()
{
    int vertices,edges;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&vertices);
    if(vertices <= 0 || vertices > MAX)
    {
        printf("\n Invalid input.. ! exiting..!");
        return 0;
    }
    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&edges);

    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<vertices;i++)
    {
        g->head[i]=NULL;
    }

    printf("\n enter the edges in the graph : \n");
    for(int i=0;i<edges;i++)
    {
        int src,dest;
        scanf("%d %d",&src,&dest);
        add_edge(g,src,dest);
    }

    printf("\n The adjacency list is : \n");
    for(int i=0;i<vertices;i++)
    {
        printf("\n%d : ",i);
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            printf("%d - ",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }

    int *result=topological_sort(g,vertices);
    
    if(result)
    {
        printf("\n The resultant topological sort is : \n");
        for(int i=0;i<vertices;i++)
        {
            printf("%d ",result[i]);
        }
        free(result);
    }

    for(int i=0;i<vertices;i++)
    {
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            struct node *next=temp->next;
            free(temp);
            temp=next;
        }
    }
    free(g);

    return 0;
}