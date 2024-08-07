#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void infix_to_postfix(char s[]);
int precedence(char c);
char associativity(char c); 

void infix_to_postfix(char s[])
{
    char stack[1000];
        int top=-1;

    char postfix[1000];
    int index=0;

    int len=strlen(s);
    printf("\n the length is : %d",len);


    for(int i=0;i<len;i++)
    {
        char c=s[i];
        if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9')
        {
            postfix[index++]=c;
        }
        else if(c=='(')
        {
            stack[++top]=c;
        }
        else if(c==')')
        {
            while(top>=0 && stack[top]!='(')
            {
                postfix[index++]=stack[top--];
            }
            top--;
        }
        else
        {
            while(top>=0 && ((precedence(c) < precedence(stack[top])) || (precedence(c) == precedence(stack[top]) && associativity(c)=='L')))
            {
                postfix[index++]=stack[top--];
            }
            stack[++top]=c;
        }
    }
    while(top>=0)
    {
        postfix[index++]=stack[top--];
    }
    postfix[index]='\0';
    printf("\n the postfix expression is : %s",postfix);
}

int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}

char associativity(char c)
{
    if(c=='^')
        return 'R';
    return 'L';
}

int main()
{
    char a[50]="a+b-c*d/e^f";
    printf("\n the Infix expression is : %s",a);
    infix_to_postfix(a);
    return 0;
}

