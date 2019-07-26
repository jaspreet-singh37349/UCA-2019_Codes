/*
In this we make corresponding row and column to 0 in matrix

e.g.
input = [1,1,0]
        [1,0,1]
        [1,1,1]
        
output = [0,0,0]
         [0,0,0]
         [1,0,0]
*/

#include <stdio.h>

int main()
{
    int r,c;
    printf("Enter row of matrix");
    scanf("%d",&r);
    printf("Enter column of matrix");
    scanf("%d",&c);
    
    int arr[r][c],i=0,j=0,row=0,col=0;
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    // checking 1st row
    for(i=0;i<c;i++)
    {
        if(arr[0][i]==0)
        {
            row = 1;
            break;
        }
    }
    
    // checking 1st column for 0
    for(i=0;i<r;i++)
    {
        if(arr[i][0]==0)
        {
            col=1;
            break;
        }
    }
    
    //checking whole array excluding 1st row and column for 0 and updating corresponding 1st row and 1st col
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(arr[i][j]==0)
            {
                arr[0][j]=0;
                arr[i][0]=0;
            }
        }
    }
    
    // checking updated 1st row and col and making corresponding whole row or col to 0
    for(i=0;i<c;i++)
    {
        if(arr[0][i]==0)
        {
            for(j=1;j<r;j++)
            {
                arr[j][i]=0;
            }
        }
    }
    for(i=0;i<r;i++)
    {
        if(arr[i][0]==0)
        {
            for(j=1;j<c;j++)
            {
                arr[i][j]=0;
            }
        }
    }
    // Making 1st row and col to 0
    if(row==1)
    {
        for(i=0;i<c;i++)
        {
            arr[0][i]=0;
        }
    }
    if(col==1)
    {
        for(i=0;i<r;i++)
        {
            arr[i][0]=0;
        }
    }
    //printing output matrix
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
