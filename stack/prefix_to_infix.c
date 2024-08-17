#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Stack
{
    char *items[MAX];
    int top;
};


void initialize(struct Stack *stack);
void prefix_to_infix(char prefix[]);
void free_stack(struct Stack *stack);

void free_stack(struct Stack *stack)
{
    while(stack->top>=0)
    {
        free(stack->items[stack->top--]);
    }
}


void initialize(struct Stack *stack)
{
    stack->top=-1;
}

void prefix_to_infix(char prefix[])
{
    struct Stack stack;
    initialize(&stack);
    
    int length=strlen(prefix);
    printf("\n the length is : %d",length);
    for(int i=length-1;i>=0;i--)
    {
        char ch=prefix[i];
        printf("\n %c",ch);

        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9')
        {
            if(stack.top>=MAX-1)
            {
                printf("\n stack overflow");
                free_stack(&stack);
                return;
            }
            char *operand=(char*)malloc(2*sizeof(char));
            operand[0]=ch;
            operand[1]='\0';
            stack.items[++stack.top]=operand;
        }
        else if(ch=='^' || ch=='/' || ch=='*' || ch=='+' || ch=='-')
        {
            if(stack.top<1)
            {
                printf("\n stack underflow");
                free_stack(&stack);
                return;
            }
            char *operand1=stack.items[stack.top--];
            char *operand2=stack.items[stack.top--];
            
            char *expression=(char*)malloc((strlen(operand1)+strlen(operand2)+4)*sizeof(char));

            sprintf(expression, "(%s%c%s)",operand1,ch,operand2);

            stack.items[++stack.top]=expression;

            free(operand1);
            free(operand2);
        }
        else
        {
            printf("\n Invalid prefix expression");
            free_stack(&stack);
            return;
        }
    }
    if(stack.top==0)
    {
        printf("\n the infix expression is : %s",stack.items[stack.top]);
    }
    else
    {
        printf("\n Invalid prefix expression");
    }

    free_stack(&stack);
}

int main()
{
    char prefix[]="*-+ABC/DE";
    printf("\n the prefix is : %s",prefix);
    printf("\n the length is : %d",strlen(prefix));
    prefix_to_infix(prefix);
    return 0;
}