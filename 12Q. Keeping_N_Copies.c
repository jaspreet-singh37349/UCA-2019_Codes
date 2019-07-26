/*
e.g.
input -> [1,1,1,2,2,3,3,4,5,6,6,6]
Now if count = 1 then we have max of 1 copy of element
So output will be = [1,2,3,4,5]

But if count = 2 then max of 2 copy of element can be there in array
So output = [1,1,2,2,3,3,4,5,6,6]
*/

#include <stdio.h>

int main()
{
    int n,count;
    scanf("%d",&n);
    int arr[n],i=0,j=0,k,ct=1;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    scanf("%d",&count);
    
    for(i=1;i<n;i++)
    {
        if(arr[i]!=arr[j])
        {
            ct=1;
            j++;
            arr[j] = arr[i];
        }
        else if(arr[i]==arr[j]&&ct<count)
        {
            ct++;
            j++;
            arr[j] = arr[i];
        }
    }
    
    for(i=0;i<=j;i++)
    {
        printf("%d ",arr[i]);
    }
}
