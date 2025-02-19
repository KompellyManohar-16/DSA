// GfG-Problem Link: https://bit.ly/3As1nQw
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char **path;
    int path_length;
}PathSequence;

typedef struct Queuenode
{
    PathSequence node;
    struct Queuenode *next;
}Queuenode;

typedef struct Queue
{
    Queuenode *front, *rear;
}Queue;

PathSequence *find_shortest_sequences(char **words, char *start_word, char *target_word, int n, int *result_count);
void enqueue(Queue *q, PathSequence  sequence);
PathSequence dequeue(Queue *q);
int isOneLetterDifferent(const char *word1, const char *word2);
int Queue_Empty(Queue *q);
void remove_word(char *used, char **words, int n);

void enqueue(Queue *q, PathSequence  sequence)
{
    Queuenode *newnode = (Queuenode *)malloc(sizeof(Queuenode));

    newnode->node.path = (char **)malloc(sequence.path_length * sizeof(char *));
    for(int i=0; i<sequence.path_length; i++)
    {
        newnode->node.path[i] = strdup(sequence.path[i]);
    }
    newnode->node.path_length = sequence.path_length;
    newnode->next=NULL;

    if(q->front==NULL && q->rear==NULL)
    {
        q->front = q->rear = newnode;
    }
    else
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

PathSequence dequeue(Queue *q)
{
    Queuenode *temp = q->front;

    PathSequence sequence;

    sequence.path = (char **)malloc(q->front->node.path_length * sizeof(char *));
    for(int i=0; i<q->front->node.path_length; i++)
    {
        sequence.path[i]=strdup(q->front->node.path[i]);
    }
    sequence.path_length = q->front->node.path_length;

    q->front = q->front->next;

    if(q->front == NULL)
    {
        q->rear=NULL;
    }

    for(int i=0; i<temp->node.path_length; i++)
    {
        free(temp->node.path[i]);
    }
    free(temp->node.path);

    free(temp);
    return sequence;
}

PathSequence *find_shortest_sequences(char **words, char *start_word, char *target_word, int n, int *result_count)
{
    *result_count=0;
    PathSequence *result = (PathSequence *)malloc(n * sizeof(PathSequence));

    if(strcmp(start_word,target_word)==0)
    {
        result[0].path=(char **)malloc(1 * sizeof(char *));
        result[0].path[0]=strdup(target_word);
        result[0].path_length=1;
        (*result_count)++;
        return result;
    }

    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear =NULL;

    PathSequence start;
    start.path=(char **)malloc(1 * sizeof(char *));
    start.path[0] = strdup(start_word);
    start.path_length=1;
    enqueue(q,start);

    int u=0;
    char **used_on_level = (char **)malloc((n*n) * sizeof(char *));
    used_on_level[u++]=strdup(start_word);
    int level=0;

    while( !Queue_Empty(q) )
    {
        PathSequence current_path = dequeue(q);

        if( current_path.path_length > level)
        {
            level++;
            for(int i=0; i<u; i++)
            {
                remove_word(used_on_level[i],words,n);
            }
        }

        char *last_word = current_path.path[current_path.path_length - 1];

        if( strcmp(last_word, target_word) == 0)
        {
            result[*result_count].path = (char **)malloc((current_path.path_length + 1) * sizeof(char *));
            for(int i=0; i<current_path.path_length; i++)
            {
                result[*result_count].path[i] = strdup(current_path.path[i]);
            }
            result[*result_count].path_length = current_path.path_length;
            (*result_count)++;
            continue;
        }

        for(int i=0; i<n; i++)
        {
            if( words[i] && isOneLetterDifferent( last_word, words[i] ))
            {
                PathSequence new_path;
                new_path.path=(char **)malloc( (current_path.path_length +1) * sizeof(char *));

                for(int j=0; j<current_path.path_length; j++)
                {
                    new_path.path[j] = strdup(current_path.path[j]);
                }
                new_path.path[current_path.path_length] = strdup(words[i]);
                new_path.path_length = current_path.path_length + 1;
                enqueue(q,new_path);
                used_on_level[u++]=strdup(words[i]);
            }
        }
    }
    for(int i=0;i<u;i++)
    {
        free(used_on_level[i]);
    }
    free(used_on_level);
    free(q);

    return result;
}

int isOneLetterDifferent(const char *word1, const char *word2)
{
    if( !word1 || !word2 ) return 0;
    
    int count=0;
    while( *word1 && *word2)
    {
        if( *word1 != *word2)
        {
            count++;
            if(count > 1) return 0;
        }
        word1++;
        word2++;
    }
    return count==1;
} 

int Queue_Empty(Queue *q)
{
    if( q->front == NULL && q->rear == NULL)
    {
        return 1;
    }
    return 0;
}

void remove_word(char *used, char **words, int n)
{
    for(int i=0; i<n; i++)
    {
       if(words[i])
       {
            if(strcmp(used,words[i])==0)
            {
                free(words[i]);
                words[i]=NULL;
            }
       }
    }
}


int main()
{
    int n,word_size;
    printf("\nenter no of words in the wordList : ");
    scanf("%d",&n);

    printf("\n enter the size of the word : ");
    scanf("%d",&word_size);

    char **words = (char **)malloc(n * sizeof(char *));
    for(int i=0;i<n;i++)
    {
        words[i]=(char*)malloc((word_size+1) * sizeof(char));
    }

    char *start_word=(char *)malloc((word_size+1) * sizeof(char));
    char *target_word=(char *)malloc((word_size+1) * sizeof(char));

    printf("\n enter the wordList : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",words[i]);
    }
    printf("\n enter the start word and target word : ");
    scanf("%s %s",start_word,target_word);

    printf("\nThe entered wordList is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%s ",words[i]);
    }
    printf("\nThe start word is : %s\nThe target word is : %s",start_word,target_word);

    int result_count=0;
    PathSequence *result = find_shortest_sequences(words, start_word, target_word, n, &result_count);

    if(result_count == 0)
    {
        printf("\n No possible sequences");
    }
    else
    {
        printf("\n\n The shortest path are : \n");
        for(int i=0; i<result_count; i++)
        {
            for(int j=0; j<result[i].path_length; j++)
            {
                printf("%s ",result[i].path[j]);
            }
            printf("\n");
        }
    }

    for(int i=0;i<n;i++)
    {
        if(words[i])    free(words[i]);
    }
    free(words);
    free(start_word);
    free(target_word);
    
    for(int i=0; i<result_count; i++)
    {
        for(int j=0; j<result[i].path_length; j++)
        {
            free(result[i].path[j]);
        }
        free(result[i].path);
    }
    free(result);
    return 0;
}
