

#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list <int> *arr;
    
    public: Graph(int V)
    {
        V = V;
        arr = new list<int>[V];
    }
    void addEdge(int u,int v)
    {
        arr[u].push_back(v);
    }
    void find_dfs(int v,bool visited[])
    {
        visited[v]=true;
        cout<<v<<" ";
        list<int>::iterator i;
        for(i=arr[v].begin();i!=arr[v].end();i++)
        {
            if(visited[*i]==false)
            {
                find_dfs(*i,visited);
            }
        }
    }

    void DFS(int v)
    {
        bool visited[V];
        int i;
        for(i=0;i<V;i++)
        {
            visited[i]=false;
        }
        find_dfs(v,visited);
    }
};

int main() 
{ 
    
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout<<"Enter starting vertex\n";
    int n;
    cin>>n;
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex "<<n<<") \n"; 
    g.DFS(n);
  
    return 0; 
}
