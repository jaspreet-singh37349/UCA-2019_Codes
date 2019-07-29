// we have to find 3 no's in array whose sum is closest to the number input by user
/*
e.g
input -> -1 2 1 -4
input number -> 1

output ->
Closest = 2                                  
Triplet = -1 1 2
*/
#include <stdio.h>

int cmp(const void *p,const void *q)
{
    return (*(int *)p - *(int *)q);
}

int main()
{
    int i,j,k,n,element,min=999999,sum,result,t1,t2,t3;
    scanf("%d",&n);
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    scanf("%d",&element);
    
    qsort(arr,n,sizeof(arr[0]),cmp);
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    for(i=0;i<n;i++)
    {
        j=i+1;
        k=n-1;
        for(;j<k;)
        {
            
            sum = arr[i]+arr[j]+arr[k];
            
            if((sum-element)==0)
            {
                result = sum;
                break;
            }
            else if(min>abs(sum-element))
            {
                min = abs(sum-element);
                t1 = arr[i];
                t2 = arr[j];
                t3 = arr[k];
                result = sum;
            }
            if(sum<=element)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    
    printf("\nClosest = %d\n",result);
    printf("Triplet = %d %d %d",t1,t2,t3);
}
