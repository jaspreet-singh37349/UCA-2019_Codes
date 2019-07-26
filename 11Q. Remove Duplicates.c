/*
###Given array should be sorted
e.g.
input -> [1,1,1,2,2,3,3,4,5,6,6,6]
output -> [1,2,3,4,5,6]
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i=0,j=0,k;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++)
    {
        if(arr[i]!=arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    
    for(i=0;i<=j;i++)
    {
        printf("%d ",arr[i]);
    }
}
