#include<stdio.h>
#include<string.h>

void reverse(char a[]);
void infix_to_prefix(char s[]);
int precedence(char c);
char associativity(char c);


int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
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

void reverse(char a[])
{
    int len=strlen(a);
    int start=0;
    int end=len-1;
    char temp;
    while(start<end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}

void infix_to_prefix(char s[])
{

    char stack[1000];
    int top=-1;

    char prefix[1000];
    int index=0;
    
    int len=strlen(s);


    for(int i=0;i<len;i++)
    {
        char c=s[i];
        printf("%c ",c);
        if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9')
        {
            prefix[index++]=c;
        }
        else if(c==')')
        {
            stack[++top]=c;
        }
        else if(c=='(')
        {
            while(top>=0 && stack[top]!=')')
            {
                prefix[index++]=stack[top--];
            }
            top--;
        }
        else
        {
            while(top>=0 && (precedence(c)<precedence(stack[top]) || (precedence(c)==precedence(stack[top]) && associativity(c)=='R')))
            {
                prefix[index++]=stack[top--];
            }
            stack[++top]=c;
        }
    }
    while(top>=0)
    {
        prefix[index++]=stack[top--];
    }
    prefix[index]='\0';
    reverse(prefix);
    printf("\n the prefix is : %s",prefix);
}



int main()
{
    char infix[]="a^b^c";
    printf("\n the infix expression is main : %s",infix);
    printf("\n the length is main : %d",strlen(infix));
    reverse(infix);
    printf("\n the reverse is main: %s\n",infix);
    infix_to_prefix(infix);
    return 0;
}