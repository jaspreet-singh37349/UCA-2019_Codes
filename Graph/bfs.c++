

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
    
    void BFS(int v)
    {
        bool visited[v];
        int j;
        for(j=0;j<v;j++)
        {
            visited[j]=false;
        }
        visited[v]=true;
        
        list<int> queue;
        queue.push_back(v);
        
        list<int>::iterator i; 
        
        while(!queue.empty())
        {
            int a = queue.front();
            cout<<a<<" ";
            queue.pop_front();
            
            for(i=arr[a].begin();i!=arr[a].end();i++)
            {
                if(!visited[*i])
                {
                    visited[*i]=true;
                    queue.push_back(*i);
                }
            }
        }
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
  
    cout << "Following is Bredth First Traversal"
            " (starting from vertex "<<n<<") \n"; 
    g.BFS(n);
  
    return 0; 
}
