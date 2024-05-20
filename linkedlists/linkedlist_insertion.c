#include<stdio.h>
#include<stdlib.h>

    struct node
    {
        int data;
        struct node*next;
    };
    struct node *head=NULL;
    struct node*temp=NULL;
    struct node*newnode=NULL;   

    int count=0;
        
    void insert_at_begin(int data)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("\n memory allocation failded");
            return;
        }
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
        count++;
    }


    void insert_at_end(int data)
    {
         if(head==NULL)
        {
            insert_at_begin(data);
            return;
        }
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return;
            }
            newnode->data=data;
            newnode->next=NULL;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            count++;
    }


    void insert_after_position(int data,int pos)
    {
        if(pos<1||pos>count)
        {
            printf("\n Invalid position");
            return;
        }
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return;
            }
            newnode->data=data;
            newnode->next=NULL;
            temp=head;
            while(i<pos)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            count++;
    }
    void insert_before_position(int data,int pos)
    {
        if(pos<1||pos>count+1)
        {
            printf("\n Invalid position");
            return;
        }
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return;
            }
            newnode->data=data;
            newnode->next=NULL;
            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            count++;
        
    }
    void insert_at_specific(int data,int pos)
    {
        if(pos<1||pos>count+1)
        {
            printf("\n Invalid position");
            return;
        }
        if(pos==1)
        {
            insert_at_begin(data);
            return;
        }
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                printf("\n memory allocation failed");
                return;
            }
            newnode->data=data;
            newnode->next=NULL;
            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            count++;
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
            printf("\n the elements are : ");
            printf("\n the data \t --> \t address part ");
            printf("\n the head is : %p",head);
            temp=head;
            while(temp!=NULL)
            {
                printf("\n %d \t --> \t %p",temp->data,temp->next);
                temp=temp->next;
            }
        } 
    }

    void freelist()
    {
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            free(temp);
            count--;
        }
    }

    int main()
    { 
        int choice,data,pos;

        while(1)
        {
            printf("\n 1.insert at begin");
            printf("\n 2.insert at end");
            printf("\n 3.insert at after a position");
            printf("\n 4.insert at before a position");
            printf("\n 5.insert at the specific position");
            printf("\n 6.display");
            printf("\n 7.freelist");
            printf("\n 8.exit");
            printf("\n enter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1  :printf("\n enter the data to insert at beginning : ");
                            scanf("%d",&data);
                            insert_at_begin(data);
                            break;
                case 2  :printf("\n enter the data to insert at end : ");
                            scanf("%d",&data);
                            insert_at_end(data);
                            break;
                case 3  :printf("\n enter the data and position  : ");
                            scanf("%d %d",&data,&pos);
                            insert_after_position(data,pos);
                            break;
                case 4  :printf("\n enter the data and position : ");
                            scanf("%d %d",&data,&pos);
                            insert_before_position(data,pos);
                            break;
                case 5  :printf("\n enter the data and position : ");
                            scanf("%d %d",&data,&pos);
                            insert_at_specific(data,pos);
                            break;
                case 6  :  display();
                            printf("\n the total no.of  are nodes are : %d",count);
                            break;
                case 7  : freelist();
                            printf("\n list is freed");
                            break;
                case 8  : exit(0);
                default : printf("\n Invalid choice");
            }
        }
        return 0;
    }





