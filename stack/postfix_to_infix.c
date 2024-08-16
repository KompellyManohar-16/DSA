#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Stack
{
    char* items[MAX];
    int top;
};

void postfix_to_infix(char postfix[]);
void initialize(struct Stack* stack);
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
    printf("\n the top is :%d",stack->top);
}


void postfix_to_infix(char postfix[])
{
    struct Stack stack;
    initialize(&stack);
    int length=strlen(postfix);
    printf("\n the lenght is : %d",length);

    for(int i=0;i<length;i++)
    {
        char ch=postfix[i];
        printf("\n %c",ch);


        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9')
        {
            if(stack.top>=MAX-1)
            {
                printf("\n stack overflow");
                free_stack(&stack);
                return ;
            }
            char *operand=(char *)malloc(2*sizeof(char));
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
            char *operand2=stack.items[stack.top--];
            char *operand1=stack.items[stack.top--];

            char *expression=(char *)malloc((strlen(operand1)+strlen(operand2)+4)*sizeof(char));

            sprintf(expression ,"(%s%c%s)",operand1,ch,operand2);
            stack.items[++stack.top]=expression;

            free(operand1);
            free(operand2);
        }
    }
    if(stack.top==0)
    {
        printf("\n the infix expression is : %s",stack.items[stack.top]);
    }
    else
    {
        printf("\n Invalid postfix expression");
    }
    free_stack(&stack);
    printf("\n the top is :%d",stack.top);
}

int main()
{
    char postfix[]="ABC*+D/";
    printf("\n the postfix expression is : %s",postfix);
    printf("\n the length is : %d",strlen(postfix));
    printf("\n add is : %p",postfix);
    printf("\n %p",&postfix[0]);
    printf("\n %c",postfix[0]);

    postfix_to_infix(postfix);
    
    return 0;
}