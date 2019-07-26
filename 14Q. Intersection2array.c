/*
###Given array should be sorted
e.g.
input -> 
A = [1,1,2,2,3,3,3,4,5]
B = [3,3,5]

output -> [3,3,5]
*/

#include <stdio.h>

int main()
{
    int n,m,i,j;
    printf("Enter size of 1st array");
    scanf("%d,&n);
    printf("Enter size of 2nd array");
    scanf("%d,&m);
    int a[n],b[m];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }

    for(i=0,j=0;i<n&&j<m;)
    {
        if(a[i]<b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
        else
        {
            printf("%d ",a[i]);
            i++;
            j++;
        }
    }
    
    

    return 0;
}
