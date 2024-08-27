#include<stdio.h>
#define MAX 10

int stack1[MAX],stack2[MAX];
int top1=-1,top2=-1;
int count=0;

void enqueue(int data)
{
    if(top1>=MAX-1)
    {
        printf("\n stack overflow");
        return;
    }
    stack1[++top1]=data;    //pushing the data into stack1
    count++;                //incrementing the count variable for each element
}

void dequeue()
{
    if(top1<0 && top2<0)
    {
        printf("\n stack underflow");
        return;
    }
   if(top2<0)
   {
        while(top1>=0)
        {
            stack2[++top2]=stack1[top1--];
        }
   }
    printf("\n the dequeue element is : %d",stack2[top2--]);
    count--;
}

void display()
{
    if(top1<0 && top2<0)
    {
        printf("\n the queue is empty");
        return;
    }
    printf("\n the queue elements are : ");
    for(int i=top2;i>=0;i--)
    {
        printf("%d\t",stack2[i]);
    }
    for(int i=0;i<=top1;i++)
    {
        printf("%d\t",stack1[i]);
    }
    printf("\n the total no.of elements are : %d",count);
}


int main()
{
    int data,choice;
    while(1)
    {
        printf("\n\n 1. enqueue");
        printf("\n 2. dequeue");
        printf("\n 3. display");
        printf("\n 4. exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        enqueue(data);
                        break;
            case 2  : dequeue();
                        break;
            case 3  : display();
                        break;
            case 4  : return 0;
            default : printf("\n Invalid choice");
        }
    }
    return 0;
} 


// void dequeue() {
//     if(top1 < 0) {
//         printf("\nStack underflow");
//         return;
//     }

//     // Transfer all elements from stack1 to stack2
//     while(top1 >= 0) {
//         stack2[++top2] = stack1[top1--];
//     }

//     // Directly dequeue the front element from stack2
//     printf("\nThe dequeued element is: %d", stack2[top2--]);
//     count--;  // Decrement count

//     // Transfer all elements back to stack1
//     while(top2 >= 0) {
//         stack1[++top1] = stack2[top2--];
//     }
// }
