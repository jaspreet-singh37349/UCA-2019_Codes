#include <stdio.h>
#include <stdlib.h>

int min=0,max=0;

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

void find_width(bst* root,int dist)
{
    if(min>dist)
    {
        min=dist;
    }
    if(max<dist)
    {
        max=dist;
    }
    
    if(root->left)
    {
        find_width(root->left,dist-1);
    }
    if(root->right)
    {
        find_width(root->right,dist+1);
    }
}

void inorder(bst* root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
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
    
    find_width(root,0);

    printf("minimum distance = %d\n",min);
    printf("maximum distance = %d\n",max);

    printf("width of tree = %d",abs(min)+max+1);
    
    //inorder(root);
    return 0;
}
