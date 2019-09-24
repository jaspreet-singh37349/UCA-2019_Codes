
#include <stdio.h>

int hcf(int a,int b)
{
    return (b,a%b);
}

int main()
{
    int a,b;
    
    scanf("%d %d",&a,&b);
    
    int h = hcf(a,b);

    printf("%d",h);
    return 0;
}
