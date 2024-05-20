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

int count=0;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
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
    count++;
}

void delete_at_begin()
{
    if(head==NULL)
    {
        printf("\n List is empty , deletion is not possible");
        return;
    }
    temp=head;
    head=head->next;
    printf("\n deleted node is : ");
    printf("\n %d \t --> \t %p",temp->data,temp->next);
    free(temp);
    count--;
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("\n List is empty , deletion is not possible");
        return;
    }
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
    count--;
}

void delete_at_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n List is empty , deletion is not possible");
        return;
    }
    if(pos<1||pos>count)
    {
        printf("\n Invalid position");
        return;
    }
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
    count--;
}

void delete_after_pos(int pos)
{
    if(head==NULL)
    {
        printf("\n List is empty , deletion is not possible");
        return;
    }
    if(pos<1||pos>=count)
    {
        printf("\n Invalid position");
        return;
    }
    int i=1;
    struct node* nextnode=NULL;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    printf("\n the deleted node is : ");
    printf("\n %d \t --> \t %p",nextnode->data,nextnode->next);
    free(nextnode);
    count--;
}
 void delete_before_pos(int pos)
 {
    if(head==NULL)
    {
        printf("\n List is empty , deletion is not possible");
        return;
    }
    if(pos<=1||pos>count)
    {
        printf("\n Invalid position");
        return;
    }
    if(pos==2)
    {
        delete_at_begin();
        return;
    }
    int i=1;
    struct node *prev=NULL;
    temp=head;
    while(i<pos-1)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    printf("\n the deleted node is : ");
    printf("\n %d \t --> \t %p",temp->data,temp->next);
    free(temp);
    count--;
 }

void display()
{
    if(head==NULL)
    {
        printf("\n the head is : %p",head);
        printf("\n List is empty");
    }
    else
    {
        temp=head;
        printf("\n the elements are : ");
        printf("\n the data \t --> \t the address");
        printf("\n the head is : %p",head);
        while(temp!=NULL)
        {
            printf("\n %d \t --> \t %p",temp->data,temp->next);
            temp=temp->next;
        }
    }
    printf("\n the total no.of nodes are : %d",count);   
}


int main()
{
    int data,pos,choice;
    while(1)
    {
        printf("\n 1.insertion");
        printf("\n 2.delete at begin");
        printf("\n 3.delete at end");
        printf("\n 4.delete after a position");
        printf("\n 5.delete before a position");
        printf("\n 6.delete at a specific position");
        printf("\n 7.display");
        printf("\n 8.exit");
        printf("\n enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : printf("\n enter the data : ");
                        scanf("%d",&data);
                        insert(data);
                        break;
            case 2  : delete_at_begin();
                        break;
            case 3  : delete_at_end();
                        break;
            case 4  : printf("\n enter the positon : ");
                        scanf("%d",&pos);
                        delete_after_pos(pos);
                        break;
            case 5  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        delete_before_pos(pos);
                        break;
            case 6  : printf("\n enter the position : ");
                        scanf("%d",&pos);
                        delete_at_pos(pos);
                        break;
            case 7  : display();
                        break;
            case 8  : exit(0);
            default : printf("\n Invalid choice");
        }
    }
    return 0;

}