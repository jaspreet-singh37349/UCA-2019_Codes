
#include <stdio.h>

long long int power(int no,int expo)
{
    if(expo==1)
    {
        return no;
    }
    if(expo==0)
        return 1;
    
    if(expo%2==0)
    {
        return power(no*no,expo/2);
    }
    else
    {
        return no*power(no*no,expo/2);
    }
}

int main()
{
    int no,expo;
    
    scanf("%d %d",&no,&expo);
    long long int ans = power(no,expo);
    
    printf("%lld",ans);
}
