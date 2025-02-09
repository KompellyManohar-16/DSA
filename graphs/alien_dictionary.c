#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25

struct node
{
    int data;
    struct node *next;
};

struct graph
{
    struct node *head[MAX];
};

char *find_order(char **words, int no_of_words, int no_of_letters);
void add_edge(struct graph *g, int a, int b);

char *find_order(char **words, int no_of_words, int no_of_letters)
{
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
    if(g==NULL)
    {
        printf("\n memory allocation for graph is failed");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<no_of_letters;i++)
    {
        g->head[i]=NULL;
    }


    for(int i=0; i < no_of_words - 1; i++)
    {
        char *str1=words[i];
        char *str2=words[i+1];

        int len1=strlen(str1);
        int len2=strlen(str2);

        int length= (len1 < len2) ? len1 : len2;

        if( (strncmp(str1,str2,length) == 0 ) && (len1>len2) )
        {
            printf("\n Not possible to determine the order becoz of invalid dictionary");
            free(g);
            return NULL;
        }

        for(int j=0; j<length; j++)
        {
            if(str1[j] != str2[j])
            {
                int a=str1[j]-'a';
                int b=str2[j]-'a';
                add_edge(g,a,b);
                break;
            }
        }
    }

    printf("\n The adjacence list is : \n");
    for(int i=0; i<no_of_letters; i++)
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

    int *in_degree=(int *)malloc(no_of_letters * sizeof(int));
    int *result=(int *)malloc(no_of_letters * sizeof(int));
    int *queue=(int *)malloc(no_of_letters * sizeof(int));
    int r=0,front =0,rear=0;


    for(int i=0;i<no_of_letters;i++)
    {
        in_degree[i]=0;
    }

    for(int i=0;i<no_of_letters;i++)
    {
        struct node *temp=g->head[i];
        while(temp!=NULL)
        {
            in_degree[temp->data]++;
            temp=temp->next;
        }
    }

    for(int i=0;i<no_of_letters;i++)
    {
        if(in_degree[i]==0)
        {
            queue[rear++]=i;
        }
    }

    while(front < rear)
    {
        int current=queue[front++];
        result[r++]=current;

        struct node *temp = g->head[current];
        while(temp!=NULL)
        {
            in_degree[temp->data]--;

            if(in_degree[temp->data] == 0 )
            {
                queue[rear++]=temp->data;
            }
            temp=temp->next;
        }
    }

    for(int i=0;i<no_of_letters;i++)
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
    free(in_degree);
    free(queue);

    if(r != no_of_letters)
    {
        printf("\n Not possible to determine the order due to cycle");
        free(result);
        return NULL;
    }

    char *order=(char *)malloc((no_of_letters+1) * sizeof(char));
    for(int i=0;i<no_of_letters;i++)
    {
        order[i]=result[i]+'a';
    }
    order[no_of_letters]='\0';

    return order;
}

void add_edge(struct graph *g, int a, int b)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newnode->data=b;
    newnode->next=g->head[a];
    g->head[a]=newnode;
}

int main()
{
    int no_of_words,no_of_letters;

    printf("\n enter the no of letters in the alien dictionary : ");
    scanf("%d",&no_of_letters);

    printf("\n enter the no of words : ");
    scanf("%d",&no_of_words);

    char **words=(char **)malloc(no_of_words * sizeof(char *));
    for(int i=0;i<no_of_words;i++)
    {
        words[i]=(char *)malloc(50 * sizeof(char));   
    }

    getchar();

    printf("\n enter the words from the alien dictionary : \n");
    for(int i=0;i<no_of_words;i++)
    {
        scanf(" %[^\n]",words[i]);    // the space before %[^\n] is to consume the leftover newnline...
    }

    printf("\n The entered words from the dictionary are : \n");
    for(int i=0;i<no_of_words;i++)
    {
        printf("\n%s",words[i]);
    }

    char *order=find_order(words, no_of_words, no_of_letters);
    if(order)
    {
        printf("\n The order of the letter is : \n");
        printf("\n%s",order);
        free(order);
    }
    else
    {
        printf("\n Not possible to determine the order of the letters in the alien dictionary");
    }

    for(int i=0;i<no_of_words;i++)
    {
        free(words[i]);
    }
    free(words);

    return 0;
}