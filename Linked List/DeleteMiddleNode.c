
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

struct node* deleteMid(struct node *head)
{
     // Your Code Here
     if(head==NULL||head->next==NULL)
        return NULL;
    else
    {
        struct node *ptr = head;
        struct node *curr = head->next;
        
        while(curr->next&&curr->next->next)
        {
            ptr = ptr->next;
            curr=curr->next->next;
        }
        
        curr = ptr->next->next;
        free(ptr->next);
        ptr->next = curr;
        
        return head;
    }
}

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to delete middle element from list\n");
    
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
    struct node* start = deleteMid(head);
    while(start)
    {
        printf("%d ",start->data);
        start = start->next;
    }
}
