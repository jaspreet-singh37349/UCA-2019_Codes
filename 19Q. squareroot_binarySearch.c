/*
Finding square root of elemnt in given array.
If element is not perfect square then find floor of square toot of element.

e.g.
input = [1,2,3,5,6,7,9]
element = 10

output ->
Square root of 10 = 3
Index = 2
*/

#include <stdio.h>

int main()
{
    int l=0,h,i,n,mid,sq;
    
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    scanf("%d",&sq);
    
    h=n-1;
    while(l<=h)
    {
        mid = l+((h-l)/2);
        
        if(arr[mid]*arr[mid]<=sq && (arr[mid]+1)*(arr[mid]+1)>sq)
        {
            break;
        }
        else if(arr[mid]*arr[mid]<sq)
        {
            l=mid+1;
        }
        else
        {
            h = mid-1;
        }
        
    }

    printf("Square Root of %d = %d\n",sq,arr[mid]);
    printf("Index = %d",mid);
    
    return 0;
}
