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

int main()
{
    printf("Enter number to append at beginning of linked list\n");
    printf("Enter -1 to EXIT\n");
    
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
}
