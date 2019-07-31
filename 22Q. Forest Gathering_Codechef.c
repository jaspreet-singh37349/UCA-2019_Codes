/*
For problem statement visit https://www.codechef.com/problems/FORESTGA
*/

#include <stdio.h>

int main() {
	// your code goes here
	int n,i,ct=0,flag=0;
	unsigned long long int w,len,l=0,r=1000000000000000000,growth;

	scanf("%d %llu %llu",&n,&w,&len);
	
	unsigned long long int height[n],rate[n],sum=0,mid;
	
	for(i=0;i<n;i++)
	{
	    scanf("%llu %llu",&height[i],&rate[i]);
	}
	
	while(l<=r)
	{
	    sum=0;
	    mid = (l+r)/2;
	    
	    if(l==r)
	    {
	        break;
	    }
	    
	    for(i=0;i<n;i++)
	    {
	        flag=0;
	        growth = height[i]+(rate[i]*mid);
	        if(growth>=len)
	        {
	            sum+=growth;
	        }
	        if(sum>w)
	        {
	            flag=1;
	            break;
	        }
	    }
	    if(flag==0&&sum==w)
	    {
	        break;
	    }
	    if(flag==1)
	    {
	        r=mid;
	    }
	    else
	    {
	        l=mid+1;
	    }
	    
	}
	
	printf("%llu",mid);
	
	return 0;
}
