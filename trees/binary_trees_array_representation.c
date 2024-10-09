#include<stdio.h>
#define MAX 100


void binary_tree_nodes(char binary[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(binary[i]=='-')
        {
            continue;
        }
        printf("%c\t",binary[i]);
    }
}
void binary_tree_array_representation(char binary[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%c ",binary[i]);
    }
}

void binary_tree_node_relationship(char binary[],int n)
{
    char left_child,right_child,parent;
    for(int i=0;i<n;i++)
    {
        if(binary[i]=='-')
        {
            continue;
        }
        printf("\n\n Node is : %c",binary[i]);

        //left child
        printf("\n Left child is : ");
        if(2*i+1 < MAX)
        {
            left_child=binary[2*i+1];
            if(left_child!='-')
            {
                printf("%c",left_child);
            }
            else
            {
                printf("NULL");
            }
        }
        else
        {
            printf("NULL");
        }

        //right child
        printf("\n Right child is : ");
        if(2*i+2 < MAX)
        {
            right_child=binary[2*i+2];
            if(right_child!='-')
            {
                printf("%c",right_child);
            }
            else
            {
                printf("NULL");
            }
        }
        else
        {
            printf(" NULL");
        }

        //parent
        printf("\n Parent is :");
        if(i==0)
        {
            printf("ROOT NODE");
        }
        else
        {
            parent=binary[(i-1)/2];
            printf("%c",parent);
        }
    }
}

int main()
{
    char binary[MAX];
    for(int i=0;i<MAX;i++)
    {
        binary[i]='-';
    }
    char left_child,right_child;
    int no_of_nodes=0;    
    int array_index=0;           // no_of_nodes = no.of nodes in the binary tree


    printf("\n enter the root node of the tree (use - for NULL) : \n");
    scanf(" %c",&binary[0]);

    if(binary[0]=='-')
    {
        printf("\n the tree is empty");
        printf("\n the no.of nodes are : %d",no_of_nodes);
        return 0;
    }

    no_of_nodes++;
    printf("\n The Root node is : %c",binary[0]);
  

    for(int i=0;i<=array_index;i++)
    {
        if(binary[i]=='-')
        {
            printf("\n i value : %d array_index is : %d",i,array_index); //skipping,ignore this stmt
            continue;
        }

        printf("\n enter the left child of %c which is at index %d (use - for NULL) : ",binary[i],i);
        scanf(" %c",&left_child);

        if(2*i+1 < MAX)
        {
            if(left_child!='-')
            {
                binary[2*i+1]=left_child;
                no_of_nodes++;
            }
            else
            {
                binary[2*i+1]='-';
            }
        }
        else
        {
            printf("\n array size exceeded");
            break;
        }

        printf("\n enter the right child of %c which is at index %d (use - for NULL) : ",binary[i],i);
        scanf(" %c",&right_child);
        
        if(2*i+2 < MAX)
        {
            if(right_child!='-')
            {
                binary[2*i+2]=right_child;
                no_of_nodes++;
            }
            else
            {
                binary[2*i+2]='-';
            }
        }
        else
        {
            printf("\n array size exceeded");
            break;
        }
        array_index=2*i+2;
    }

    printf("\n Binary tree nodes : ");
    binary_tree_nodes(binary,array_index+1);

    printf("\n Binary tree in array representation : ");
    binary_tree_array_representation(binary,array_index+1);

    printf("\n Binary tree node relationship : ");
    binary_tree_node_relationship(binary,array_index+1);

    printf("\n The total no.of nodes are : %d",no_of_nodes);

    return 0;
}