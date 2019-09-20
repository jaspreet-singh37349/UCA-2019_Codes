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

int find_n_by_k(struct node *curr, int k)
{
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    dummy->next=curr;
    int ct=0;
    struct node *elem=dummy;
    
    while(curr)
    {
        ct++;
        
        if(ct==k)
        {
            ct=0;
            elem=elem->next;
        }
        else
        {
            if(curr->next==NULL)
            {
                elem=elem->next;
            }
        }
        
        curr=curr->next;
    }
    
    return elem->data;
}

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to exit\n");
    
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
    int k;
    printf("Enter k to find n/k th node in linked list.(n is length of linked list)\n");
    printf("Output will be value stored at ceil of n/k th node\n");
    scanf("%d",&k);
    int ans = find_n_by_k(head,k);
    printf("%d",ans);
}
