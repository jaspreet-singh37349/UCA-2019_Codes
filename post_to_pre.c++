
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s,res;
    cout<<"Enter postfix expression\n";
    cin>>s;
    vector<string>v;
    int i;
    
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            string b = v.back();
            v.pop_back();
            string a = v.back();
            v.pop_back();
            string ss = " ";
            ss[0]=s[i];
            ss=ss+a+b;
            v.push_back(ss);
        }
        else
        {
            string str = " ";
            str[0] = s[i];
            v.push_back(str);
        }
    }
    cout<<"Prefex Expression -> "<<v.back();

    return 0;
}
