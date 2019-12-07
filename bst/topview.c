/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;

tree* node(int data)
{
    tree* new_node = (tree*)malloc(sizeof(tree));
    new_node->data = data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

tree* createTree(tree* root,int data)
{
    if(root==NULL)
    {
        tree* new_node = node(data);
        return new_node;
    }
    
    if(data<root->data)
        root->left = createTree(root->left,data);
    else
        root->right = createTree(root->right,data);
        
    return root;
}

void preorder(tree* root)
{
    if(root==NULL)
        return;
    
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int min=0,max=0,size=250;

void tp(tree* root,int arr[],int dist)
{
    if(root==NULL)
        return;
    
    if(dist<min)
    {
        min=dist;
        arr[size+min]=root->data;
    }
    else if(dist>max)
    {
        max=dist;
        arr[size+max]=root->data;
    }
    
    tp(root->left,arr,dist-1);
    tp(root->right,arr,dist+1);
}

void topview(tree* root)
{
    if(root==NULL)
        return;
        
    int i;
    int* arr = (int *)calloc(size*2,sizeof(int));
    
    arr[250] = root->data;
    
    tp(root,arr,0);
    
    for(i=min+size;i<=max+size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n,i,a;
    tree* root = NULL;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        root = createTree(root,a);
    }
    
    topview(root);
}
