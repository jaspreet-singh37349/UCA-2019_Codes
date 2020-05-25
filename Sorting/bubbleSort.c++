#include <iostream>

using namespace std;

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int n,int arr[])
{
    int i,j;
    bool swapped;
    for(i=0;i<n-1;i++)
    {
        swapped=false;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped=true;
            }
        }
        
        if(swapped==false)
            break;
    }
    
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    bubbleSort(n,arr);
    
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
