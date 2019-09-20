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

void remove_duplicates(struct node *h)
{
    struct node *temp;
    
    while(h&&h->next)
    {
        if(h->data==h->next->data)
        {
            temp = h->next;
            h->next = h->next->next;
            free(temp);
        }
        else
        {
            h=h->next;
        }
    }
}

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to remove all duplicate values\n");
    
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
    remove_duplicates(head);
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start = start->next;
    }
}
