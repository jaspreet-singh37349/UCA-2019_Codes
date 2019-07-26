

#include <stdio.h>

int main()
{
    int l=0,h,i,n,mid,elem;
    
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    scanf("%d",&elem);
    
    h=n-1;
    while(l<=h)
    {
        mid = l+((h-l)/2);
        
        if(arr[mid]==elem)
        {
            break;
        }
        if(arr[mid]<elem)
        {
            l=mid+1;
        }
        else
        {
            h = mid-1;
        }
        
    }

    printf("found element %d",arr[mid]);
    
    return 0;
}
