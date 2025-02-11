// GfG-Problem Link: https://bit.ly/3PuJxk3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int word_ladder(char **words, char *start, char *target, int n);
int word_search(char **words, char *current, int n);

int word_ladder(char **words, char *start, char *target, int n)
{
    int len=strlen(start);

    struct node
    {
        char *c;
        int seq_no;
    };

    struct node queue[MAX];
    int front=0,rear=0;

    queue[rear].c=strdup(start);
    queue[rear].seq_no=1;
    rear++;

    while(front < rear)
    {
        char *current_word = queue[front].c;
        int current_seq_no = queue[front].seq_no;
        front++;

        char *original=(char *)malloc((len+1) * sizeof(char));
        strcpy(original,current_word);

        for(int i=0; i < len; i++)
        {
            for(char ch='a'; ch<='z'; ch++)
            {
                if(original[i] == ch) continue;

                current_word[i]=ch;

                if( word_search(words, current_word, n) == 1)
                {
                    if( strcmp(current_word, target) == 0)
                    {
                        free(original);
                        for(int j=0; j<rear; j++)
                        {
                            free(queue[j].c);
                        }
                        return current_seq_no+1;
                    }
                    queue[rear].c = strdup(current_word);
                    queue[rear].seq_no = current_seq_no+1;
                    rear++;
                }
            }
            strcpy(current_word,original);
        }
        free(original);
    }

    for(int i=0; i<rear; i++)
    {
        free(queue[i].c);
    }
    return 0;
}

int word_search(char **words, char *current, int n)
{
    for(int i=0;i<n;i++)
    {
        if( words[i]!=NULL && strcmp(words[i] , current) == 0 )
        {
            free(words[i]);
            words[i]=NULL;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n,word_size;
    printf("\n enter the no of words in the wordlist : ");
    scanf("%d",&n);

    printf("\n enter the size of word : \n");
    scanf("%d",&word_size);

    char **words=(char **)malloc(n * sizeof(char *));
    for(int i=0;i<n;i++)
    {
        words[i]=(char *)malloc(word_size+1 * sizeof(char));
    }

    printf("\n enter the wordlist : ");
    for(int i=0;i<n;i++)
    {
        scanf("%s",words[i]);
    }

    char *start_word = (char *)malloc(word_size+1 * sizeof(char));
    char *target_word = (char *)malloc(word_size+1 * sizeof(char));

    printf("\n enter the start word and target word : \n");
    scanf("%s %s",start_word,target_word);

    printf ("\n The wordlist is : \n");
    for(int i=0;i<n;i++)
    {
        printf("\n%s ",words[i]);
    }
    printf("\nstart word is : %s \ntarget word is : %s",start_word,target_word);

    int result=word_ladder(words,start_word,target_word,n);
    printf("\n The shortest transformation sequence is : %d",result);

    for(int i=0;i<n;i++)
    {
        if(words[i]!=NULL) 
        {
            free(words[i]);
        }
    }
    free(words);
    free(start_word);
    free(target_word);

    return 0;
}