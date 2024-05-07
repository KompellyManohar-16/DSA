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
        
     void insertatbegin(int data)
     {
        newnode=(struct node*)malloc(sizeof(struct node));
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
     }
    void insertatend(int data)
    {
         if(head==NULL)
        {
            insertatbegin(data);
        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            newnode->next=NULL;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    void insertafterposition(int data,int pos,int count)
    {
        if(pos>count)
        {
            printf("\n Invalid position");
        }
        else
        {
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
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
        }
    }
    void insertbeforeposition(int data,int pos,int count)
    {
        if(pos>count)
        {
            printf("\n Invalid position");
        }
        else{
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
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
        }
    }
    void insertatspecific(int data,int pos,int count)
    {
        if(pos<1||pos>count+1)
        {
            printf("\n Invalid position");
        }
        else if(pos==1)
        {
            insertatbegin(data);
        }
        else
        {
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
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
        }
        


    }
    void display()
    {
        printf("\n the elements are : ");
        printf("\n the data --> address part ");
        temp=head;
        while(temp!=NULL)
        {
            printf("\n %d\t--->%u",temp->data,temp->next);
            temp=temp->next;
        }
    }

    void freelist()
    {
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            free(temp);
        }
    }

    int main()
    { 
        int choice,data,pos;
        int count=0;

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
                            insertatbegin(data);
                            count++;
                            break;
                case 2  :printf("\n enter the data to insert at end : ");
                            scanf("%d",&data);
                            insertatend(data);
                            count++;
                            break;
                case 3  :printf("\n enter the data and position  : ");
                            scanf("%d %d",&data,&pos);
                            insertafterposition(data,pos,count);
                            count++;
                            break;
                case 4  :printf("\n enter the data and position : ");
                            scanf("%d %d",&data,&pos);
                            insertbeforeposition(data,pos,count);
                            count++;
                            break;
                case 5  :printf("\n enter the data and position : ");
                            scanf("%d %d",&data,&pos);
                            insertatspecific(data,pos,count);
                            count++;
                            break;
                case 6  :  display();
                            printf("\n the total no.of elements are : %d",count);
                            break;
                case 7  : freelist();
                            printf("\n list is freed");
                            count=0;
                            break;
                case 8  : exit(0);
                default : printf("\n Invalid choice");
            }
        }
        return 0;
    }





