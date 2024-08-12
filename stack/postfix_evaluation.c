#include<stdio.h>
#include<string.h>
#include<ctype.h>


int postfix_evaluation(char a[]);
int power(int base,int exponent);

int power(int base, int exponent)
{
    int power=1;
    for(int i=exponent;i>=1;i--)
    {
        power*=base;
    }
    return power;
}

int postfix_evaluation(char a[])
{
   int stack[1000];
   int top=-1;

   int len=strlen(a);
   printf("\n the length is : %d",len); 

   for(int i=0;i<len;i++)
   {
        if(isspace(a[i]))
        {
            continue;
        }
        if(isdigit(a[i]))
        {
            int num=0;
            while(i<len && isdigit(a[i]))
            {
                num=(num*10)+(a[i]-'0');
                i++;
            }
            stack[++top]=num;
            i--;
            printf("\n the num is : %d",num);
        }
        else if(a[i]=='^' || a[i]=='/' || a[i]=='*' || a[i]=='+' || a[i]=='-')
        {
            int result;
            int operand2=stack[top--];
            int operand1=stack[top--];
            switch(a[i])
            {
                case '^'    : result=power(operand1,operand2);
                                break;
                case '/'    : if(operand2==0)
                                {
                                    printf("\n error by division by zero");
                                    return -1;
                                }
                                result=operand1/operand2;
                                break;
                case '*'    : result=operand1*operand2;
                                break;
                case '+'    : result=operand1+operand2;
                                break;
                case '-'    : result=operand1-operand2;
                                break;
            }
            printf("\n the result : %d",result);
            stack[++top]=result;
            printf("\n the topmost element is : %d",stack[top]);
        }
        else
        {
            printf("\n Invalid postfix expression");
            return -1;
        }
   }
   if(top!=0)
   {
        printf("\n Invalid postfix expression");
        return -1;
   }
   return stack[top];
}

int main()
{
    char postfix[]="150 30 12 * 75 / 60 20 * + 100 - +";
    printf("\n the postfix expression is : %s",postfix);
    int res=postfix_evaluation(postfix);
    printf("\n the result is : %d",res);
    return 0;
}