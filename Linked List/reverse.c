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

void reverse(struct node **h)
{
    struct node* prev = NULL;
    struct node* curr = *h;
    struct node* new = curr->next;
    
    while(curr)
    {
        new = curr->next;
        curr->next = prev;
        prev = curr;
        curr = new;
    }
    *h=prev;
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
    reverse(&head);
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
