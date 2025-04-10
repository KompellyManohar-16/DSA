#include<stdio.h>
#include<stdlib.h>
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

struct edge
{
    int v1;
    int v2;
};

struct MST
{
    struct edge arr[MAX];
    int size;
    int sum;
};

struct queue_node
{
    int weight;
    int node;
    int parent;
    struct queue_node *next;
};

struct MST *prims_alg(struct graph *g, int n, int e);
struct queue_node *enqueue(struct queue_node *pq, int wt, int nd, int pt);
int is_empty(struct queue_node *pq);
struct queue_node *dequeue(struct queue_node **pq);
void create_graph(struct graph *g, int e);


struct MST *prims_alg(struct graph *g, int n, int e)
{
    int *visited = (int *)calloc(n, sizeof(int));

    struct MST *tree = (struct MST *)malloc(sizeof(struct MST));
    tree->size = 0;
    tree->sum = 0;

    struct queue_node *pq = NULL;
    pq = enqueue(pq,0,0,-1);

    while(!is_empty(pq))
    {
        struct queue_node *current = dequeue(&pq);
        int current_weight = current->weight;
        int current_node = current->node;
        int current_parent = current->parent;

        free(current);

        if( !visited[current_node] )
        {
            visited[current_node] = 1;
            tree->sum = tree->sum + current_weight;

            if(current_parent != -1)
            {
                tree->arr[tree->size].v1 = current_parent;
                tree->arr[tree->size].v2 = current_node;
                (tree->size)++;
            }

            struct node *temp = g->head[current_node];
            while(temp!=NULL)
            {
                if( !visited[temp->data] )
                {
                    pq = enqueue(pq, temp->weight, temp->data, current_node);
                }
                temp = temp->next;
            }
        }
    }

    free(visited);

    return tree;
}

struct queue_node *enqueue(struct queue_node *pq, int wt, int nd, int pt)
{
    struct queue_node *newnode = (struct queue_node *)malloc(sizeof(struct queue_node));
    if(!newnode)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newnode->weight = wt;
    newnode->node = nd;
    newnode->parent = pt;
    newnode->next = NULL;

    if(pq == NULL || wt < pq->weight)
    {
        newnode->next = pq;
        pq = newnode;
    }
    else
    {
        struct queue_node *temp = pq;

        while(temp->next!=NULL && temp->next->weight <= wt)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return pq;
}


int is_empty(struct queue_node *pq)
{
    if(pq == NULL)
    {
        return 1;
    }
    return 0;
}

struct queue_node *dequeue(struct queue_node **pq)
{
    if( (*pq) == NULL)
    {
        return NULL;
    }
    
    struct queue_node *head = (*pq);
    (*pq) = (*pq)->next;

    return head;
}


void create_graph(struct graph *g, int e)
{
    printf("\n enter the edges in the graph with the weight(src -- dest -- weight) : ");

    for(int i=0; i<e; i++)
    {
        int src,dest,wt;
        scanf("%d %d %d",&src, &dest, &wt);
        
        struct node *newnode_1 = (struct node *)malloc(sizeof(struct node));
        if(!newnode_1)
        {
            printf("\n memory allocation failed");
            exit(EXIT_FAILURE);
        }

        newnode_1->data = dest;
        newnode_1->weight = wt;

        newnode_1->next = g->head[src];
        g->head[src] = newnode_1;

        struct node *newnode_2 = (struct node *)malloc(sizeof(struct node));
        if(!newnode_2)
        {
            printf("\n memory allocation failed");
            exit(EXIT_FAILURE);
        }

        newnode_2->data = src;
        newnode_2->weight = wt;

        newnode_2->next = g->head[dest];
        g->head[dest] = newnode_2;
    }
}

int main()
{
    int n,e;
    printf("\n enter no of vertices in the graph : ");
    scanf("%d",&n);

    if(n<=0 || n>MAX)
    {
        printf("\nNo of vertices exceeds the limit");
        return 0;
    }
    printf("\n enter no of edges in the graph : ");
    scanf("%d",&e);

    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    if(!g)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<MAX;i++)
    {
        g->head[i] = NULL;
    }


    create_graph(g,e);

    printf("\n The adjacency list is : \n");
    for(int i=0; i<n; i++)
    {
        printf("\n%d : ",i);
        struct node *head = g->head[i];
        while(head != NULL)
        {
            printf("%d %d- ",head->data, head->weight);
            head = head->next;
        }
        printf("NULL");
    }


    struct MST *tree = prims_alg(g,n,e);

    printf("\n The Minimum Spanning Tree is : \n");
    for(int i=0; i<tree->size; i++)
    {
        printf("\n%d - %d",tree->arr[i].v1, tree->arr[i].v2);
    }
    printf("\n The Minimum Spanning Tree Cost is : %d",tree->sum);
    printf("\n The size is : %d",tree->size);

    for(int i=0; i<n; i++)
    {
        struct node *temp = g->head[i];
        while(temp!=NULL)
        {
            struct node *next = temp->next;
            free(temp);
            temp=next;
        }
    }
    free(g);
    free(tree);

    return 0;
}