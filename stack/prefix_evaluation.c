#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int prefix_evaluation(char a[]);
int power(int base, int exponent);

int power(int base, int exponent)
{
    int result=1;
    for(int i=exponent;i>0;i--)
    {
        result*=base;
    }
    return result;
}

int prefix_evaluation(char a[])
{
    int stack[1000];
    int top=-1; 

    int len=strlen(a);
    int i=len-1;
    printf("\n the length is : %d and last index is : %d",len,i);

    while(i>=0)
    {
        printf("\n at %d the character is : %c",i,a[i]);

        while(i>=0 && isspace(a[i]))
        {
            printf("\n at %d the character is : %c  ",i,a[i]);
            i--;
        }
        printf("\n at %d the character is : %c  ",i,a[i]);
        if(i<0)
        {
            break;
        }
        if(isdigit(a[i]))
        {
            int num=0;
            int base=1;

            while(i>=0 && isdigit(a[i]))
            {
                num=num+(a[i]-'0')*base;
                base*=10;
                i--;
                printf("\n at %d the character is : %c  ",i,a[i]);
            }
            i++;
            printf("\n at %d the character is : %c  ",i,a[i]);
            stack[++top]=num;
            printf("\n the top is : %d",stack[top]);
        }
        else if(a[i]=='/' || a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='^')
        {
            if(top<1)
            {
                printf("\n Invalid prefix expression");
                return -1;
            }
            int result;
            int operand1=stack[top--];
            int operand2=stack[top--];
            printf("\n the operands are : %d %d",operand1,operand2);
            switch(a[i])
            {
                case '^'  : result=power(operand1,operand2);
                            printf("\n the power is : %d",result);
                            break;
                case '/'  : if(operand2==0)
                                {
                                    printf("\n error division by zero");
                                    return -1;
                                } 
                            result=operand1/operand2;
                            break;
                case '*'  : result=operand1*operand2;
                            break;
                case '+'  : result=operand1+operand2;
                            break;
                case '-'  : result=operand1-operand2;
                            break;
            }
            printf("\n the result is : %d",result);
            stack[++top]=result;
            printf("\n after push : %d",stack[top]);
        }
        i--;
    }
    if(top!=0)
    {
        printf("\n Invalid prefix expression");
        return -1;
    }
    printf("\nthe result is : %d",stack[top]);
    return stack[top];
}

int main()
{
    char prefix[]="- + 2 * 3 4 / 16 ^ 2 3";
    int res=prefix_evaluation(prefix);
    printf("\n the reslut is %d",res);
    return 0;
}