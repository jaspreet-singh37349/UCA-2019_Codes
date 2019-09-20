#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void InsertAtBeg(struct node **h,int no)
{
    struct node* new_node = (struct node *) malloc(sizeof(struct node));
    
    new_node->data = no;
    new_node->next = (*h);
    
    (*h) = new_node;
}

void DeleteLast(struct node *h)
{
    if(h==NULL)
    {
        return;
    }
    if(h->next==NULL)
    {
        free(h);
        h=NULL;
        return;
    }
    
    while(h->next->next)
    {
        h=h->next;
    }
    free(h->next);
    h->next = NULL;
}

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to delete last node\n");
    
    int n=0;
    struct node* head = NULL;
    
    while(n!=-1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        else
        {
            InsertAtBeg(&head,n);
            struct node* start = head;
            while(start!=NULL)
            {
                printf("%d ",start->data);
                start = start->next;
            }
        }
        printf("\n");
    }
    struct node* start = head;
    DeleteLast(head);
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start = start->next;
    }
}
