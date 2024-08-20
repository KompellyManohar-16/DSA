#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;


void balanced_brackets(char brackets[])
{
    int len=strlen(brackets);
    for(int i=0;i<len;i++)
    {
        char ch=brackets[i];
        printf("\n\n bracket is : %c",ch);
        if(ch=='{' || ch=='[' || ch=='(')
        {
            if(top>=MAX-1)
            {
                printf("\n stack overflow- too many opening brackets");
                return;
            }
            stack[++top]=ch;            //push operation
            printf("\n stack top is : %c",stack[top]);
        }
        else if( ch=='}' ||  ch==']'  || ch==')')
        {
           if(top<0)
           {
                printf("\n stack underflow - too many closing brackets");
                return;
           }
           if( (ch=='}' && stack[top]=='{') || (ch==']' && stack[top]=='[') || (ch==')' && stack[top]=='(') )
            {
                    char c=stack[top--];         //pop operation
                    printf("\n pairs are : %c %c",c,ch);
            }
            else
            {
                printf("\n MISMATCHED BRACKETS");
                return;
            }
        }
        // else
        // {
        //     printf("\n INVALID EXPRESSION");
        //     return;
        // }
    }
    if(top<0)
    {
        printf("\n BALANCED");
    }
    else
    {
        printf("\n  NOT BALANCED");
    }
}

int main()
{
    char expression[]="(({8-9}[8*7])22)";      // for NOT BALANCED expression is :({)}[]
    printf("\n the brackets are : %s",expression);
    printf("\n the length is : %d",strlen(expression));
    balanced_brackets(expression);
    return 0;
}