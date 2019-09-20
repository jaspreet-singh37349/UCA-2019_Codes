#include <stdio.h>

typedef struct stack{
    int data;
    struct stack *next;
}Stack;

int isempty(Stack *h)
{
    if(h==NULL)
        return 1;
    else
        return 0;
}

void push(Stack **h,int no)
{
    Stack* new_node = (Stack *) malloc(sizeof(Stack));
    
    new_node->data = no;
    new_node->next = (*h);
    
    (*h) = new_node;
}

int pop(Stack** h)
{
    if(isempty(*h))
        return;
    int a;
    Stack *curr=*h;
    a=curr->data;
    *h=(*h)->next;
    free(curr);
    return a;
}

int top(Stack *h)
{
    if(isempty(h))
        return NULL;
    else
    {
        return h->data;
    }
}

int main()
{
    int n,i,a;
    printf("Enter size of stack\n");
    scanf("%d",&n);
    
    Stack* head = NULL;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        push(&head,a);
    }
    printf("Stack =");
    for(i=0;i<n;i++)
    {
        printf(" %d ",top(head));
        pop(&head);
    }
}
