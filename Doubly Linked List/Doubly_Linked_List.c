#include <stdio.h>

typedef struct LinkedList{
    int data;
    struct LinkedList *next;
    struct LinkedList *prev;
}dblyLinkedList;

dblyLinkedList *front=NULL;
dblyLinkedList *rear=NULL;

void InsertAtFront(int data)
{
    dblyLinkedList* new_node = (dblyLinkedList *) malloc(sizeof(dblyLinkedList));
    
    new_node->data = data;
    new_node->next = front;
    new_node->prev=NULL;
    
    
    if(front!=NULL)
    {
        front->prev=new_node;
    }
    else
    {
        rear=new_node;
    }
    front = new_node;
}

void InsertAtEnd(int data)
{
    dblyLinkedList* new_node = (dblyLinkedList *) malloc(sizeof(dblyLinkedList));
    
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev=rear;
    
    
    if(rear!=NULL)
    {
        rear->next=new_node;
    }
    else
    {
        front=new_node;
    }
    rear = new_node;
}

void Delete_Front()
{
    dblyLinkedList *curr=front;
    if(front==NULL)
        return;    
    else if(front->next==NULL)
    {
        front=NULL;
        rear=NULL;
        free(curr);
    }
    else
    {
        front=front->next;
        front->prev = NULL;
        free(curr);
    }
}

void Delete_Last()
{
    dblyLinkedList *curr=rear;
    if(rear==NULL)
        return;
    else if(rear->prev==NULL)
    {
        front=NULL;
        rear=NULL;
        free(curr);
    }
    else
    {
        rear=(rear)->prev;
        rear->next=NULL;
        free(curr);
    }
}

int main()
{
    int n;
    printf("Enter 1 to insert at starting\n");
    printf("Enter 2 to delete from starting\n");
    printf("Enter 3 to insert at end\n");
    printf("Enter 4 to delete from end\n");
    printf("Enter -1 to Exit\n");
    while(n!=-1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        else
        {
            if(n==1)
            {
                printf("Enter number to insert\n");
                scanf("%d",&n);
                InsertAtFront(n);
            }
            else if(n==2)
            {
                Delete_Front();
            }
            else if(n==3)
            {
                printf("Enter number to insert\n");
                scanf("%d",&n);
                InsertAtEnd(n);
            }
            else if(n==4)
            {
                Delete_Last();
            }
            dblyLinkedList* start = front;
            printf("LinkedList from starting = ");
            while(start!=NULL)
            {
                printf("%d ",start->data);
                start = start->next;
            }
            printf("\n");
            start = rear;
            printf("LinkedList from end = ");
            while(start!=NULL)
            {
                printf("%d ",start->data);
                start = start->prev;
            }
        }
        printf("\n");
    }

    return 0;
}
