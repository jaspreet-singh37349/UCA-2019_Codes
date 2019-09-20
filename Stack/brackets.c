#include <stdio.h>

typedef struct stack{
    char c;
    struct stack *next;
}Stack;

int isempty(Stack *h)
{
    if(h==NULL)
        return 1;
    else
        return 0;
}

void push(Stack **h,char ch)
{
    Stack* new_node = (Stack *) malloc(sizeof(Stack));
    
    new_node->c = ch;
    new_node->next = (*h);
    
    (*h) = new_node;
}

char pop(Stack** h)
{
    if(isempty(*h))
        return NULL;
    char a;
    Stack *curr=*h;
    a=curr->c;
    *h=(*h)->next;
    free(curr);
    return a;
}

char top(Stack *h)
{
    if(isempty(h))
        return NULL;
    else
    {
        return h->c;
    }
}

int check_brackets(char *arr,int n)
{
    int i;
    Stack *head = NULL;
    
    for(i=0;i<n;i++)
    {
        if(isempty(head))
        {
            push(&head,arr[i]);
        }
        else if((arr[i]==')'&&top(head)=='(')||(arr[i]==']'&&top(head)=='[')||(arr[i]=='}'&&top(head)=='{'))
        {
            pop(&head);
        }
        else
        {
            push(&head,arr[i]);
        }
    }
    
    if(isempty(head))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n,i;
    char c;
    printf("Enter size of string\n");
    scanf("%d",&n);
    
    char arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf(" %c",&arr[i]);
    }
    
    if(check_brackets(&arr[0],n))
        printf("Equation is valid");
    else
        printf("Equation is not valid");
}
