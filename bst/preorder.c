/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

void preorder(bst* root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
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
    
    preorder(root);

    return 0;
}
