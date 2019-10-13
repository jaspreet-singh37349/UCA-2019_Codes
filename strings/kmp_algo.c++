
#include <iostream>

using namespace std;

void lps(string pat,int* arr)
{
    int i=1,j=0;
    int n = pat.length();
    
    while(i<n)
    {
        if(pat[i]==pat[j])
        {
            j++;
            arr[i]=j;
            i++;
        }
        else
        {
            if(j>0)
            {
                j = arr[j-1];
            }
            else
            {
                arr[i]=0;
                i++;
            }
        }
    }
    
}

void kmp(string txt,string pat)
{
    int n = txt.length();
    int m = pat.length();
    
    int i=0,j=0;
    
    int* lpss = (int*)calloc(m,sizeof(int));
    lps(pat,lpss);
    
    while(i<n)
    {

        if(j==m)
        {
            printf("Pattern found at %d\n",i-j);
            j=lpss[j-1];
        }
        else if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lpss[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(j==m)
    {
        printf("Pattern found at %d\n",i-j);
        j=lpss[j-1];
    }
    
}


int main()
{
    string txt,pat;
    cin>>txt>>pat;

    kmp(txt,pat);
    return 0;
}
