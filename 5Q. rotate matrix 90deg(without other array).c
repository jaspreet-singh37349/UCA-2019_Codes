/*

e.g.
input -> [1,2,3]
          [4,5,6]
          [7,8,9]
          
output -> [7,4,1]
          [8,5,2]
          [9,6,3]
*/

#include <stdio.h>

int main()
{
    int r,c,i,ct=1,j;
    scanf("%d %d",&r,&c);
    
    int arr[r][c];
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            arr[i][j]=ct++;
        }
    }
    
    printf("Original matrix = \n");
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    printf("Rotated matrix = \n");
    
    for(i=0;i<r/2;i++)
    {
        for(j=i;j<c-1-i;j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[r-1-j][i];
            arr[r-1-j][i] = arr[r-1-i][c-1-j];
            arr[r-1-i][c-1-j] = arr[j][c-1-i];
            arr[j][c-1-i] = temp;
        }
    }
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
