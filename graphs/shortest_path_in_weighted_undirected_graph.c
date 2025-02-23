// GfG-Problem Link: https://bit.ly/3SlYvLp
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INFINITY INT_MAX
#define MAX 100

struct node
{
    int data;
    int weight;
    struct node *next;
};

struct graph
{
    struct node *head[MAX];
};

struct queue_node
{
    int distance;
    int node;
    struct queue_node *next;
};

int *dijkstra(int v, int e, int **edges, int source, int *result_count);
void create_graph(struct graph *g, int e, int **edges);
int *reverse(int *arr, int n);
int is_empty(struct queue_node *pq);
struct queue_node *enqueue(struct queue_node *pq, int d, int n);
struct queue_node *dequeue(struct queue_node **pq);


int *dijkstra(int v, int e, int **edges, int source, int *result_count)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    if(!g)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for(int i=1; i<=v; i++)
    {
        g->head[i]=NULL;
    }

    create_graph(g,e,edges);

    printf("\n The adjacency list is : \n");
    for(int i=1;i<=v;i++)
    {
        printf("\n%d : ",i);
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            printf("%d %d --> ",temp->data,temp->weight);
            temp=temp->next;
        }
        printf("NULL");
    }

    int *parent = (int *)malloc((v+1) * sizeof(int));
    int *dist = (int *)malloc((v+1) * sizeof(int));
    for(int i=1;i<=v;i++)
    {
        parent[i]=i;
        dist[i]=INFINITY;
    }

    struct queue_node *pq=NULL;
    pq=enqueue(pq,0,source);
    dist[source]=0;

    while(!is_empty(pq))
    {
        struct queue_node *current = dequeue(&pq);
        int current_distance =current->distance;
        int current_vertex = current->node;
        free(current);

        struct node *temp = g->head[current_vertex];
        while(temp!=NULL)
        {
            if(current_distance + temp->weight < dist[temp->data])
            {
                dist[temp->data]=current_distance + temp->weight;
                pq=enqueue(pq,dist[temp->data],temp->data);
                parent[temp->data] = current_vertex;
            }
            temp=temp->next;
        }
    }

    for(int i=1;i<=v;i++)
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

    if(dist[v]==INFINITY)
    {
        free(parent);
        free(dist);
        return NULL;
    }

    printf("\n The dist is : \n");
    for(int i=1;i<=v;i++)
    {
        printf("%d ",dist[i]);
    }

    int *result=(int *)malloc((v) * sizeof(int));
    *result_count=0;

    int node=v;
    while( node != source)
    {
        result[(*result_count)++] = node;
        node=parent[node];
    }
    result[(*result_count)++] = source;
    int *final_result = reverse(result, (*result_count));

    free(result);
    free(parent);
    free(dist);

    return final_result;
}

int *reverse(int *arr, int size)
{
    int *reverse_order = (int *)malloc(size *sizeof (int));

    for(int i=0;i<size;i++)
    {
        reverse_order[i]=arr[size-i-1];
    }
    return reverse_order;
}

int is_empty(struct queue_node *pq)
{
    if(pq==NULL)
    {
        return 1;
    }
    return 0;
}

struct queue_node *enqueue(struct queue_node *pq, int d, int n)
{
    struct queue_node *newnode = (struct queue_node *)malloc(sizeof(struct queue_node));
    if(!newnode)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->distance = d;
    newnode->node=n;
    newnode->next = NULL;

    if(pq == NULL || pq->distance > d)
    {
        newnode->next = pq;
        pq=newnode;
    }
    else
    {
        struct queue_node *temp=pq;
        while(temp->next!=NULL && temp->next->distance < d)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return pq;
}

struct queue_node *dequeue(struct queue_node **pq)
{
    if((*pq)==NULL)    return NULL;

    struct queue_node *head = (*pq);
    (*pq)=(*pq)->next;
    return head;
}
void create_graph(struct graph *g, int e, int **edges)
{
    for(int i=0; i<e; i++)
    {      
        int src = edges[i][0];
        int dest = edges[i][1];
        int wt = edges[i][2];  
        struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
        if(!newnode1)
        {
            printf("\n memory allocation failed..\n");
            exit(EXIT_FAILURE);
        }
        newnode1->data = dest;
        newnode1->weight = wt;
        newnode1->next = g->head[src];
        g->head[src] = newnode1;

        struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
        if(!newnode2)
        {
            printf("\n memory allocation failde..\n");
            exit(EXIT_FAILURE);
        }
        newnode2->data = src;
        newnode2->weight = wt;
        newnode2->next = g->head[dest];
        g->head[dest] = newnode2;
    }
}

int main()
{
    int v,e;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&v);
    printf("\n enter the no of edges in the graph : ");
    scanf("%d",&e);

    if(v <= 0 || v >= MAX || e <= 0 || e >= MAX)
    {
        printf("\n Invalid input..exiting...!");
        return 0;
    }

    int **edges = (int **)malloc(e * sizeof(int *));
    for(int i=0; i<e; i++)
    {
        edges[i] = (int *)malloc(3 * sizeof(int));
    }

    printf("\n The edges in the graph with the weight : \n");
    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d",&edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("\n The edges are : \n");
    for(int i=0; i<e; i++)
    {
        printf("\n %d %d %d",edges[i][0],edges[i][1],edges[i][2]);
    }

    int source;
    printf("\n enter the source : ");
    scanf("%d",&source);

    int result_count=0;
    int *result = dijkstra(v,e,edges,source,&result_count);

    if(result)
    {
        printf("\n The shortest path from the source %d to the destination %d is : ",source,v);
        for(int i=0; i<result_count; i++)
        {
            printf("%d ",result[i]);
        }
    }
    else
    {
        printf("\n The shortest path is not possible");
    }

    for(int i=0;i<e;i++)
    {
        free(edges[i]);
    }
    free(edges);
    free(result);
    return 0;
}