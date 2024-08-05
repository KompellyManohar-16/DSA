#include <stdio.h>

#define SIZE 5
int a[SIZE];
int top=-1;


void push(int data)
{   
    if(top==SIZE-1)
    {
        printf("\n  Stack Overflow");
    }
    else
    {
        top++;
        a[top]=data;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\n Stack Underflow");
    }
    else
    {
        int del=a[top];
        top--;
        printf("\n the deleted element is : %d",del);
        
    }
}

void peek()
{
    if(top==-1)
    {
        printf("\n the stack is empty");
    }
    else
    {
        printf("\n the top most element is : %d",a[top]);
    }
}

void display()
{
    if(top==-1)
    {
        printf("\n the stack is empty");
    }
    else
    {
        printf("\n the stack elements are : ");
        for(int i=top;i>=0;i--)
        {
            printf("\n %d",a[i]);
        }
        printf("\n the total no.of elements are : %d",top+1);
    }
}

int isEmpty()
{
    if(top==-1)
    {
        printf("\n TRUE");
        return 1;
    }
    else
    {
        printf("\n FALSE");
        return 0;
    }
}

int   isFull()
{
    if(top==SIZE-1)
    {
        printf("\n TRUE");
        return 1;
    }
    else
    {
        printf("\n FALSE");
        return 0;
    }
}

int main()
{
    int data,choice;
    while(1)
    {
        printf("\n\n 1. push");
        printf("\n 2. pop");
        printf("\n 3. peek");
        printf("\n 4. display");
        printf("\n 5. isEmpty");
        printf("\n 6. isFull");
        printf("\n 7. exit");
        printf("\n enter your choice : ");
        if (scanf("%d", &choice) != 1)  // Check if the input is a valid integer
        {
            printf("\nInvalid input. Please enter a number.");
            // Clear the input buffer
            while (getchar() != '\n');
                continue;
        }
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                       if (scanf("%d", &data) != 1)
                        {
                            printf("\nInvalid input. Please enter a valid number.");
                            while (getchar() != '\n');
                            continue;
                        }
                        push(data);
                        break;
            case 2  : pop();
                        break;
            case 3  : peek();
                        break;
            case 4  : display();
                        break;
            case 5  : isEmpty();
                        break;
            case 6  : isFull();
                        break;
            case 7  : return 0;
            default : printf("\n Invalid choice");

        }
    }
}