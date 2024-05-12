#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data; 
    struct node* next;
};
struct node* head=NULL;
struct node* temp=NULL;
struct node* newnode=NULL;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
    }

    if(head==NULL)
    {
        head=newnode;
            }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void deleteatbegin()
{
    temp=head;
    head=head->next;
    printf("\n deleted node is : ");
    printf("\n %d \t --> \t %p",temp->data,temp->next);
    free(temp);
}

void deleteatend()
{
    struct node* prev=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
    }
    else
    {
        prev->next=NULL;
    }
    printf("\n deleted node is : ");
    printf("\n %d \t --> \t %p",temp->data,temp->next);
    free(temp);
}

void deleteatpos(int pos)
{
    int i=1;
    struct node* prev=NULL;
    temp=head;
    if(pos==1)
    {
        head=head->next;
    }
   else
   {
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
         prev->next=temp->next;
   }
    printf("\n deleted node is : ");
    printf("\n %d \t --> \t %p",temp->data,temp->next);
    free(temp);
}

void display()
{
    if(head==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        temp=head;
        printf("\n the elements are : ");
        printf("\n the data\t-->\tthe address");
        printf("\n the head is : %p",head);
        while(temp!=NULL)
        {
            printf("\n %d \t --> \t %p",temp->data,temp->next);
            temp=temp->next;
        }
    }
    
}


int main()
{
    int data,pos,choice;
    while(1)
    {
        printf("\n 1.insertion");
        printf("\n 2.delete at begin");
        printf("\n 3.delete at end");
        printf("\n 4.delete at a position");
        printf("\n 5.display");
        printf("\n 6.exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : deleteatbegin();
                        break;
            case 3  : deleteatend();
                        break;
            case 4  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        deleteatpos(pos);
                        break;
            case 5  : display();
                        break;
            case 6  : exit(0);
            default : printf("\n Invalid choice");
        }
    }

}