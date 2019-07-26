/*
### Array should be in descending order
Reversing elements along with groups in array
e.g.
array = [8,7,6,5,4,3,2,1]
We have to reverse in group of 3 then ->
output -> [6,7,8] [3,4,5] [1,2] 

We have to do this in complexity  = O(N)
*/

#include <stdio.h>

int main()
{   
    int k,n,i,j,m;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter group size");
    scanf("%d",&k);
    
    for(i=0;i<n;i+=k)
    {
        if(i+k<=n)
        {
            for(j=0;j<k/2;j++)
            {
                m=arr[i+j];
                arr[i+j]=arr[i+k-1-j];
                arr[i+k-1-j]=m;
            }
        }
        else
        {
            for(j=0;j<(n%k)/2;j++)
            {
                m=arr[i+j];
                arr[i+j]=arr[i+(n%k)-1-j];
                arr[i+(n%k)-1-j]=m;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
