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

void RemoveAll(struct node **h)
{
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    prev->next = *h;
    struct node *ptr1 = prev;
    struct node *ptr2 = *h;
    
    while(ptr2!=NULL)
    {
        while(ptr2->next!=NULL&&ptr1->next->data==ptr2->next->data)
        {
            ptr2=ptr2->next;
        }
        
        if(ptr1->next==ptr2)
        {
            ptr1 = ptr1->next;
        }
        else
        {
            ptr1->next = ptr2->next;
        }
        
        ptr2 = ptr2->next;
    }
    
    *h = prev->next;
}

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to to print appended linked list in reverse\n");
    
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
    RemoveAll(&head);
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
