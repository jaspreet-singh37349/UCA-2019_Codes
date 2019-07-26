/*
Here two arrays of same size will be given and 1st element of 1st array will specify start of range and 1st element
of 2nd array will specify end of range.
Now we have to find out which element has occured for the most time.

e.g.
a = [2,1,3]
b = [5,3,9]

Now we have to find element which has occured for the most time in range 2-5,1-3,3-9

output -> 3
*/


#include <stdio.h>

int main()
{
    printf("Hello World\n");
    
    int x,n,i,max=-99999,m=-99999,min=99999;
    scanf("%d",&n);

    int L[n],R[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&L[i]);
        scanf("%d",&R[i]);
    }
    
    for(i=0;i<n;i++)
    {
        if(max<R[i])
        {
            max=R[i];
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(min>L[i])
        {
            min=L[i];
        }
    }
    
    int arr[max+1];
    
    for(i=0;i<=max;i++)
    {
        arr[i]=0;
    }
    
    
    
    for(i=0;i<n;i++)
    {
        arr[L[i]]++;
        arr[R[i]+1]--;
    }
    
    
    for(i=min;i<=max;i++)
    {
        arr[i]+=arr[i-1];
        if(m<arr[i])
            m=i;
    }
    
    
    printf("%d",m);
    
    return 0;
}
