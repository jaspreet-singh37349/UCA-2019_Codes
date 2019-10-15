
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

int height(bst* root)
{
    if(root==NULL)
        return 0;
    
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    if(left_height>right_height)
        return left_height+1;
    else
        return right_height+1;
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
    
    int h = height(root);
    printf("%d",h);
}
