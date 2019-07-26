/*
In this we have to find maximum contiguous sum of array from best possible subarray

e.g.
input -> [-2,1,-3,4,-1,2,1,-5,4]

Now best subarray containing max sum = [4,-1,2,1]
sum = 4-1+2+1=6
So output = 6
*/

#include <stdio.h>

int main()
{
    int n,i,sum=-9999,max=0;
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++)
    {
       max = max + arr[i];
       
       if(sum<max)
       {
           sum = max;
       }
       
       
       if(max<0)
       {
           max=0;
       }
    }
    
    printf("%d",sum);

    return 0;
}
