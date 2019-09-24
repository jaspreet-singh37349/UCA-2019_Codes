#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
  int data;
  struct bst* left;
  struct bst* right;
}bst;

typedef struct queue{
    bst* node;
    struct queue* next;
}queue;

queue* last=NULL;

void push(queue** head,bst* root)
{
    queue* new_node = (queue*)malloc(sizeof(queue));
    new_node->node=root;
    new_node->next=NULL;
    
    if(*head==NULL)
    {
        last=new_node;
        (*head)= new_node;
    }
    else
    {
        last->next=new_node;
        last=new_node;
    }
}

bst* front(queue* head)
{
    return head->node;
}

int empty(queue* head)
{
    if(head==NULL)
        return 1;
    else
        return 0;
}

void pop(queue** head)
{
    queue* temp=(*head);
    (*head)=(*head)->next;
    free(temp);
}



bst* createTree(bst* root,int data)
{
    if(root==NULL)
    {
        bst* new_node = (bst*)malloc(sizeof(bst));
        
        new_node->data=data;
        new_node->left=NULL;
        new_node->right=NULL;
        
        return new_node;
    }
    else
    {
        if(data>root->data)
        {
            root->right=createTree(root->right,data);
        }
        else
        {
            root->left=createTree(root->left,data);
        }
        return root;
    }
}

void levelorder(bst* root)
{
    if(root==NULL)
        return;
    else
    {
        queue* q = NULL;
        push(&q,root);
        
        while(!empty(q))
        {
            bst* child = front(q);
            
            if(child->left!=NULL)
                push(&q,child->left);
            if(child->right!=NULL)
                push(&q,child->right);
                
            printf("%d ",child->data);
            pop(&q);
        }
    }
}

int main()
{
    int n,i,a;
    bst* root=NULL;
    
    printf("Enter nodes of binary search tree to enter\n");
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        root = createTree(root,a);
    }
    
    levelorder(root);

    return 0;
}
