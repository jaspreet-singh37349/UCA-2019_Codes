#include<limits.h>
#include<vector>
#include<iostream>

using namespace std;


/*
    E.g. Input = () =>
    {
        9
        14
        0 1 4
        0 7 8
        1 2 8
        1 7 11
        7 8 7
        7 6 1
        2 8 2
        2 3 7
        2 5 4
        8 6 6
        6 5 2
        3 5 14
        3 4 9
        4 5 10
        0
    }
    
*/


void printGraph(int arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i*n+j]<<" ";
        }
        
        cout<<endl;
    }
    
}

void printSol(int dist[],int n,int start)
{
    int i;
    cout<<"StartVertex  Vertex  MIN_distance\n";
    for(i=0;i<n;i++)
    {
        cout<<"     "<<start<<"          "<<i<<"         "<<dist[i]<<endl;
    }
}

int minDistance(int dist[],bool visited[],int n)
{
    int i;
    int minn = INT_MAX;
    int min_idx=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==false&&dist[i]<=minn)
        {
            minn=dist[i];
            min_idx = i;
        }
    }
    
    return min_idx;
}

void Dijkstra(int arr[],int n,int start)
{
    bool visited[n];
    int dist[n];
    int i,j;
    
    for(i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    
    dist[start]=0;
    
    for(i=0;i<n-1;i++)
    {
        int min_indx = minDistance(dist,visited,n);
        visited[min_indx]=true;
        
        for(j=0;j<n;j++)
        {
            if(visited[j]==false&&arr[min_indx*n+j]&&dist[min_indx]!=INT_MAX&&dist[min_indx]+arr[min_indx*n+j]<dist[j])
            {
                dist[j]=dist[min_indx]+arr[min_indx*n+j];
            }
        }
        
        printSol(dist,n,start);
    }
}

int main()
{
    
    int n,m,i;
    cout<<"Enter no. of nodes\n";
    cin>>n;
    
    cout<<"Enter no. of queries\n";
    cin>>m;
    
    if(m)
        cout<<"Now for each query enter two nodes and distance b/w them\n";
    
    int arr[n*n]={0};
    
    for(i=0;i<m;i++)
    {
        int u,v,dist;
        cin>>u>>v>>dist;
        arr[u*n+v]=dist;
        arr[v*n+u]=dist;
    }
    
    int start;
    cout<<"Now Enter starting node to find shortest path from that node\n";
    cin>>start;
    
    Dijkstra(arr,n,start);
    
    return 0;
}
