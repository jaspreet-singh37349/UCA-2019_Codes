/*
input size of array = 4,4

output = [1,2,3,4]
         [12,13,14,5]
         [11,16,15,6]
         [10,8,8,7]
*/

#include <stdio.h>

int main()
{
    int r,c,a=0,b=0,ct=1,i,j,n,m;
    printf("Enter rows of matrix");
    scanf("%d",&r);
    printf("Enter columns of matrix");
    scanf("%d",&c);

    n=r;
    m=c;

    int arr[r][c];
    
    for(;a<=r&&b<=c;)
    {
        for(i=b;i<c;i++)
        {
            arr[a][i] = ct++;
        }
        a++;
        
        for(i=a;i<r;i++)
        {
            arr[i][c-1] = ct++;
        }
        c--;
        
        for(i=c-1;i>=b;i--)
        {
            arr[r-1][i] = ct++;
        }
        r--;
        
        for(i=r-1;i>=a;i--)
        {
            arr[i][b] = ct++;
        }
        b++;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    
}
