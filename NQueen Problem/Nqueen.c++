

#include <iostream>

using namespace std;

void print_sol(int arr[],int n)
{
    static int ct=1;
    cout<<"Arrangement No. "<<ct<<endl;
    int i;
    for(i=0;i<n*n;i++)
    {
        if(arr[i]==1)
            cout<<"Q ";
        else
            cout<<". ";
            
        if((i+1)%n==0)
            cout<<endl;
    }
    ct++;
}

bool isSafe(int arr[],int row,int col,int n)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(arr[row*n+i])
            return false;
    }
    i=row;
    j=col;
    
    for(;i>=0&&j>=0;i--,j--)
    {
        if(arr[i*n+j])
            return false;
    }
    i=row;
    j=col;
    
    for(;j>=0&&i<n;i++,j--)
    {
        if(arr[i*n+j])
            return false;
    }
    
    return true;
}

bool nqq(int arr[],int col,int n)
{
    if(col==n)
    {
        print_sol(arr,n);
        return true;
    }
    
    bool res = false;
    
    for(int i=0;i<n;i++)
    {
        if(isSafe(arr,i,col,n))
        {
            arr[i*n+col]=1;
            res = nqq(arr,col+1,n)||res;
            arr[i*n+col]=0;
        }
    }
}

void nq(int n)
{
    int arr[n*n]={0};
    nqq(arr,0,n);
}

int main()
{
    int n;
    cout<<"Please Input size of chess\n";
    cin>>n;
    nq(n);
}
