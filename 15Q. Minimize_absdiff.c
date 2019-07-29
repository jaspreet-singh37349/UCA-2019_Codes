#include <stdio.h>


int main()
{
    
    int m,n,x,i,j,k,min=999999;
    
    scanf("%d %d %d",&m,&n,&x);
    
    int a[m],b[n],c[x];
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    
    for(i=0;i<x;i++)
    {
        scanf("%d",&c[i]);
    }
    
    for(i=0,j=0,k=0;i<m&&j<n&&k<x;)
    {
        
        if(a[i]>=b[j]&&a[i]>=c[k])
        {
            if(b[j]<=c[k])
            {
                if(min>a[i]-b[j])
                    min = a[i]-b[j];
                    
                j++;
            }
            else
            {
                if(min>a[i]-c[k])
                    min = a[i]-c[k];
                
                k++;
            }
        }
        else if(b[j]>=a[i]&&b[j]>=c[k])
        {
            if(a[i]<=c[k])
            {
                if(min>b[j]-a[i])
                    min = b[j]-a[i];
                
                i++;
            }
            else
            {
                if(min>b[j]-c[k])
                    min = b[j]-c[k];
                k++;
            }
        }
        else
        {
            if(a[i]<=b[j])
            {
                if(min>c[k]-a[i])
                    min = c[k]-a[i];
                i++;
            }
            else
            {
                if(min>c[k]-b[j])
                    min = c[k]-b[j];
                j++;
            }
            k++;
        }
    }
    
    printf("%d",min);
    
    return 0;
}
