#include <iostream>

using namespace std;

int main()
{
    string str;
    string pat;
    
    cin>>str>>pat;
    string s=pat+"$"+str;
    
    int i,n=s.length(),l=0,r=0,x=pat.length();
    cout<<s<<endl;
    int arr[n];
    arr[0]=0;
    for(i=1;i<n;i++)
    {
        if(i>r)
        {
            l=r=i;
            
            for(;r<n,s[r-l]==s[r];r++);
            
            arr[i]=r-l;
            r--;
        }
        else
        {
            if(arr[i-l]+i>r)
            {
                l=i;
                
                for(;r<n,s[r-l]==s[r];r++);
                
                arr[i]=r-l;
                r--;
            }
            else
            {
                arr[i]=arr[i-l];
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            cout<<i-pat.length()-1<<endl;
        }
    }
    

    return 0;
}
