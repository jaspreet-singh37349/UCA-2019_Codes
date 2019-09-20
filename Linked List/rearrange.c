/*
e.g.
input -> 1 2 3 4 5 6
output-> 1 6 2 5 3 4 

e.g.
input -> 1 2 3 4 5
output-> 1 5 2 4 3
*/


#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void InsertAtEnd(struct node **h,int no)
{
    struct node* new_node = (struct node *) malloc(sizeof(struct node));
    
    new_node->data = no;
    new_node->next = NULL;
    
    struct node* curr = *h;
    
    if(*h==NULL)
    {
        *h=new_node;
    }
    if(curr!=NULL){
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    }
}

struct node* reverse(struct node* h)
{
    struct node* prev = NULL;
    struct node* curr = h;
    struct node* neww;
    
    while(curr)
    {
        neww = curr->next;
        curr->next = prev;
        prev = curr;
        curr = neww;
    }
    return prev;
}

void rearrange(struct node *h){
    
    if(h!=NULL&&h->next!=NULL&&h->next->next!=NULL)
    {
        struct node *head;
        struct node *slow = h;
        struct node *fast = h;
    
        while(fast->next&&fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        head = slow->next;
        
        //reversing linked list after middle
        head = reverse(head);
        
        slow->next = NULL;
        
        
        //reusing fast and slow to iterate
        slow = h;
        fast = head;
        
        while(slow)
        {
            slow = h->next;
            
            if(fast==NULL)
            {
                h->next=NULL;
                break;
            }
            fast = head->next;
            
            h->next = head;
            head->next = slow;
            
            h = slow;
            head=fast;
        }
    }
    
}

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to rearrange the linked list\n");
    
    int n=0;
    struct node* head = NULL;
    
    while(n!=-1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        else
        {
            InsertAtEnd(&head,n);
            struct node* start = head;
            while(start!=NULL)
            {
                printf("%d ",start->data);
                start = start->next;
            }
        }
        printf("\n");
    }
    rearrange(head);
    struct node* start = head;
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start = start->next;
    }
}
