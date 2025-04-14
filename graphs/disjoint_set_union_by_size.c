#include<stdio.h>
#include<stdlib.h>

struct edge
{
    int u;
    int v;
};

int * disjoint_set(struct edge *arr, int v, int e);
void union_by_size(int * parent, int *size, int vertex_1, int vertex_2, int v);
int find_ult_parent(int *parent, int node);

int * disjoint_set(struct edge *arr, int v, int e)
{
    int *size = (int *)malloc(v * sizeof(int));
    int *parent = (int *)malloc(v * sizeof(int));
    for(int i=0; i<v; i++)
    {
        size[i] = 1;
        parent[i] = i;
    }

    printf("\n Initially the parent is : ");
    for(int i=0; i<v; i++)
    {
        printf("%d ",parent[i]);
    }
    for(int i=0; i<e; i++)
    {
        int vertex_1 = arr[i].u;
        int vertex_2 = arr[i].v;

        union_by_size(parent, size, vertex_1, vertex_2, v);
    }
    
    free(size);
    return parent;
}

void union_by_size(int * parent, int *size, int vertex_1, int vertex_2, int v)
{
    // Union By Size

        int ult_parent_u = find_ult_parent(parent, vertex_1);
        int ult_parent_v = find_ult_parent(parent, vertex_2);

        if(ult_parent_u == ult_parent_v)
        {
            return;
        }
        if( size[ult_parent_u] < size[ult_parent_v] )
        {
            parent[ult_parent_u] = ult_parent_v;
            size[ult_parent_v] = size[ult_parent_u] + size[ult_parent_v];
        }
        else
        {
            parent[ult_parent_v] = ult_parent_u;
            size[ult_parent_u] = size[ult_parent_u] + size[ult_parent_v];
        }
        printf("\n After union by size of the vertices %d - %d the parent is : ",vertex_1,vertex_2);
        for(int k=0; k<v; k++)
        {
            printf("%d ",parent[k]);
        }
}


int find_ult_parent(int *parent, int node)
{
    if( node == parent[node] )
    {
        return node;
    }
    return parent[node] = find_ult_parent(parent, parent[node]);
}

int main()
{
    int v,e;
    printf("\n Enter no of vertices and no of edges in the graph : ");
    scanf("%d %d",&v,&e);

    struct edge arr[e];
    printf("\n Enter the edges in the graph : ");
    for(int i=0; i<e; i++)
    {
        scanf("%d %d",&arr[i].u, &arr[i].v);
    }

    printf("\n The edges in the graph are : ");
    for(int i=0; i<e; i++)
    {
        printf("\n%d - %d",arr[i].u, arr[i].v);
    }

    int *parent = disjoint_set(arr,v,e);

    printf("\n The final parent is : ");
    for(int i=0; i<v; i++)
    {
        printf("%d ",parent[i]);
    }

    int node_1,node_2;
    printf("\n Enter two nodes to check if they are in the same component: ");
    scanf("%d %d",&node_1, &node_2);

    if( find_ult_parent(parent,node_1) == find_ult_parent(parent,node_2) )
    {
        printf("\nNodes %d and %d are in the same component.\n", node_1, node_2);
    }
    else
    {
        printf("\nNodes %d and %d are NOT in the same component.\n", node_1, node_2);
    }

    printf("\n The parent array  After checking : \n");
    for(int i=0; i<v; i++)
    {
        printf("%d ",parent[i]);
    }

    free(parent);
    return 0;
}