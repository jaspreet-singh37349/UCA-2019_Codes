
#include <stdio.h>

int main()
{
    int n,r;
    printf("Enter size of array");
    scanf("%d",&n);
    
    int arr[n],i,m,j;
    printf("Enter elements of array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter number to rotate array to right side");
    scanf("%d",&r);
    
    r = n%r;
    
    for(i=0;i<r;i++)
    {
        m = arr[n-1];
        for(j=n-1;j>0;j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0]=m;
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
}
