#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
  int data;
  struct bst* left;
  struct bst* right;
}bst;

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

void postorder(bst* root)
{
    if(root==NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
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
    
    postorder(root);

    return 0;
}
