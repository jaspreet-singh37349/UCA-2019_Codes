#include <iostream>

using namespace std;

int isSafe(int arr[],int r,int c,bool visited[],int row,int col)
{
    return (r >= 0) && (r < row) && (c >= 0) && (c < col) && (arr[r*col+c] && !visited[r*col+c]);
    
}

void dfs(int arr[],int r,int c,bool visited[],int row,int col)
{
    //cout<<"hello";
    visited[r*col+c]=true;
    
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

    for (int k = 0; k < 8; ++k) 
        if (isSafe(arr, r + rowNbr[k], c + colNbr[k], visited,row,col)) 
            dfs(arr, r + rowNbr[k], c + colNbr[k], visited,row,col); 


}

int countIslands(int arr[],int row,int col)
{
    bool visited[row*col]={false};
    int ct=0;
    int i,j;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(arr[i*col+j]&&!visited[i*col+j])
            {
                dfs(arr,i,j,visited,row,col);
                ct++;
            }
        }
    }
    
    return ct;
}

int main()
{
    int r,c;
    cin>>r>>c;
    
    int arr[r*c];
    int i;
    
    for(i=0;i<r*c;i++)
    {
        cin>>arr[i];
    }
    
    int count = countIslands(arr,r,c);

    cout<<"Number of islands is: "<<count;

    return 0;
}
