// GfG-Problem Link1: https://bit.ly/3ApDfOm
// GfG-Problem Link2: https://bit.ly/3SYjQvp
// https://leetcode.com/problems/course-schedule/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int *is_possible(int num_courses, int** prerequisites, int prerequisites_size, int* prerequisites_column_size)
{
    int **adjacency_matrix = (int **)calloc(num_courses,sizeof(int *));
    for(int i=0;i<num_courses;i++)
    {
        adjacency_matrix[i]=(int *)calloc(num_courses,sizeof(int));
    }
    
    int *in_degree=(int *)calloc(num_courses,sizeof(int));

    for(int i=0;i<prerequisites_size;i++)
    {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];

            adjacency_matrix[b][a]=1;
            in_degree[a]++;
    }

    printf("\n The adjacency matrix is : \n");
    for(int i=0; i<num_courses; i++)
    {
        for(int j=0; j<num_courses; j++)
        {
            printf("%d ",adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n The in_degree of each vertex is : \n");
    for(int i=0;i<num_courses;i++)
    {
        printf("%d ",in_degree[i]);
    }

    int *queue=(int *)malloc(num_courses * sizeof(int));
    int front=0,rear=0;

    int *result=(int *)malloc(num_courses * sizeof(int));
    int r=0;

    for(int i=0; i < num_courses; i++)
    {
        if( in_degree[i] == 0 )
        {
            queue[rear++]=i;
        }
    }

    while( front < rear )
    {
        int current = queue[front++];
        result[r++]=current;

        for(int i=0;i<num_courses;i++)
        {
            if(adjacency_matrix[current][i] == 1)
            {
                in_degree[i]--;

                if(in_degree[i] == 0)
                {
                    queue[rear++]=i;
                }
            }
        }
    }

    for(int i=0;i<num_courses;i++)
    {
        free(adjacency_matrix[i]);
    }
    free(adjacency_matrix);
    free(in_degree);
    free(queue);

    if( r != num_courses )
    {
        printf("\n cycle detected in the graph");
        free(result);
        return NULL;
    }
    
    return result;
}

int main()
{
    int num_courses;

    printf("\n enter the no of courses : ");
    scanf("%d",&num_courses);
    if(num_courses <= 0 || num_courses > MAX)
    {
        printf("\n Invalid input..exiting..!");
        return 0;
    }

    int prerequisites_size;
    printf("\n enter the no of rows in the prerequisites : ");
    scanf("%d",&prerequisites_size);

    int prerequisites_column_size[prerequisites_size];

    printf("\n enter the column size of each prerequisites : \n");
    for(int i=0; i<prerequisites_size; i++)
    {
        scanf("%d",&prerequisites_column_size[i]);
    }

    printf("\n The prerequisites column size is : \n");
    for(int i=0; i<prerequisites_size; i++)
    {
        printf("%d ",prerequisites_column_size[i]);
    }

    int **prequisites = (int **)malloc( prerequisites_size * sizeof(int *));
    for(int i=0; i<prerequisites_size; i++)
    {
        prequisites[i]=(int *)malloc(prerequisites_column_size[i] * sizeof(int));
    }

    printf("\n enter the prerequisites array : ");
    for(int i=0; i<prerequisites_size; i++)
    {
        for(int j=0; j<prerequisites_column_size[i]; j++)
        {
            scanf("%d",&prequisites[i][j]);
        }
    }

    printf("\n The prerequisites array is : \n");
    for(int i=0; i<prerequisites_size; i++)
    {
        for(int j=0; j<prerequisites_column_size[i]; j++)
        {
            printf("%d ",prequisites[i][j]);
        }
        printf("\n");
    }

    int *result=is_possible(num_courses, prequisites, prerequisites_size, prerequisites_column_size);
    if(result)
    {
        printf("\n The correct order of the courses is : \n");
        for(int i=0;i<num_courses;i++)
        {
            printf("%d ",result[i]);
        }
        free(result);
    }
    else
    {
        printf("\n The correct order is not possible");
    }

    for(int i=0; i<num_courses ; i++)
    {
        free(prequisites[i]);
    }
    free(prequisites);
    return 0;
}