#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct edge
{
    int src;
    int dest;
    int wt;
};

struct MST
{
   struct edge arr[MAX];
    int cost;
    int size;
};

struct MST *kruskals_alg(int v, int e, struct edge *arr);
void sort(int e,struct edge *arr);
int find_ult_parent(int *parent , int n);
void union_by_rank(int *parent, int *rank, int u, int v);


struct MST *kruskals_alg(int v, int e, struct edge *arr)
{
    struct MST *tree = (struct MST *)malloc(sizeof(struct MST));
    tree->size = 0;
    tree->cost =0;

    sort(e,arr);

    printf("\nThe sorted edges are : \n");
    for(int i=0; i<e; i++)
    {
        printf("\n%d %d %d", arr[i].wt, arr[i].src, arr[i].dest);
    }

    int *parent = (int *)malloc(v * sizeof(int));
    int *rank = (int *)malloc(v *sizeof(int));
    for(int i=0; i<v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    for(int i=0; i<e; i++)
    {
        int source = arr[i].src;
        int destination = arr[i].dest;
        int w = arr[i].wt;

        if( find_ult_parent(parent, source) != find_ult_parent(parent, destination) )
        {
            tree->arr[tree->size].src = source;
            tree->arr[tree->size].dest = destination;
            tree->arr[tree->size].wt = w;
            
            tree->size++;
            tree->cost = tree->cost + w;

            union_by_rank(parent, rank, source, destination);
        }
    }
    free(rank);
    free(parent);

    return tree;
}

void sort(int e,struct edge *arr)
{
    for(int i=1; i<e; i++)
    {
        int k=i;
        struct edge temp = arr[i];
        for(int j=i-1; j>=0; j--)
        {
            if( arr[j].wt > temp.wt)
            {
                arr[k] = arr[j];
                k--;
            }
            else
            {
                break;
            }
        }
        arr[k] = temp;
    }
}

int find_ult_parent(int *parent , int n)
{
    if(n == parent[n])
    {
        return n;
    }
    return parent[n] = find_ult_parent(parent,parent[n]);
}

void union_by_rank(int *parent, int *rank, int u, int v)
{
        int ult_parent_u = find_ult_parent(parent,u);
        int ult_parent_v = find_ult_parent(parent,v);

        if( ult_parent_u == ult_parent_v )
        {
            return;
        }
        if( rank[ult_parent_u] < rank[ult_parent_v] )
        {
            parent[ult_parent_u] = ult_parent_v;
        }
        else if( rank[ult_parent_v] < rank[ult_parent_u] )
        {
            parent[ult_parent_v] = ult_parent_u;
        }
        else if( rank[ult_parent_u] == rank[ult_parent_v] )
        {
            parent[ult_parent_v] = ult_parent_u;
            rank[ult_parent_u]++;
        }
}

int main()
{
    int v,e;
    printf("\n enter the no of vertices and edges in the graph : ");
    scanf("%d %d",&v, &e);

    struct edge arr[e];
    printf("\n enter the edges in the graph (source  - destination - weight) : ");
    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d", &arr[i].src, &arr[i].dest, &arr[i].wt);
    }
    printf("\n The edges in the graph are : \n");
    for(int i=0; i<e; i++)
    {
        printf("\n%d - %d : %d",arr[i].src,arr[i].dest,arr[i].wt);
    }

    struct MST *tree = kruskals_alg(v,e,arr);

    printf("\n The Minimum Spanning Tree is : ");
    for(int i=0; i<tree->size; i++)
    {
        printf("\n%d - %d",tree->arr[i].src, tree->arr[i].dest);
    }
    printf("\n The Cost of MST is : %d",tree->cost);


    free(tree);
    return 0;
}