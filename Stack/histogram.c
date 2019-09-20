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

int maxArea(int *arr,int n)
{
    int i,max=-999999,l,area;
    Stack *s=NULL;
    
    for(i=0;i<n;)
    {
        if(isempty(s)||arr[top(s)]<=arr[i])
        {
            push(&s,i);
            i++;
        }
        else
        {
            int a = top(s);
            
            pop(&s);
            
            if(isempty(s))
            {
                l=i;
            }
            else
            {
                l=i-top(s)-1;
            }
            
            area = arr[a]*l;
            
            if(max<area)
            {
                max=area;
            }
        }
    }
    
    while(!isempty(s))
    {
        int a = top(s);
            
        pop(&s);
        
        if(isempty(s))
        {
            l=n;
        }
        else
        {
            l=n-top(s)-1;
        }
        
        area = arr[a]*l;
        
        if(max<area)
        {
            max=area;
        }
    }
    
    return max;
}

int main()
{
    int n,i,a;
    printf("Enter size\n");
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("max area = %d",maxArea(&arr[0],n));
}
