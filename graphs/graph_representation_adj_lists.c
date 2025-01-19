#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int a)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newnode->data=a;
    newnode->next=NULL;
    return newnode;
}

void add_Edge(struct node *adj_list[], int a , int b)
{
    struct node *newnode=create_node(b);
    newnode->next=adj_list[a];
    adj_list[a]=newnode;

    newnode=create_node(a);
    newnode->next=adj_list[b];
    adj_list[b]=newnode;
}

void display(struct node *adj_list[], int v)
{
    for(int i=0;i<v;i++)
    {
        printf("%d : ",i);
        struct node *temp=adj_list[i];
        while(temp!=NULL)
        {
            printf("%d --> %p  ",temp->data,temp->next);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int v;
    printf("\n enter the no of vertices in the graph : ");
    scanf("%d",&v);
    if(v==0)
    {
        printf("\n The graph is empty");
        return 0;
    }

    struct node *adj_list[v];
    for(int i=0; i<v; i++)
    {
        adj_list[i]=NULL;
    }
    
    add_Edge(adj_list,0,1);
    add_Edge(adj_list,0,3);
    add_Edge(adj_list,1,4);
    add_Edge(adj_list,1,5);
    add_Edge(adj_list,2,3);
    add_Edge(adj_list,4,5);

    printf("\n The adjacency lists representation : \n");
    display(adj_list,v);

    return 0;
}
