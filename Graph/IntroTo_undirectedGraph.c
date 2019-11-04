#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist* next;
}ll;

typedef struct newlinkedlist
{
    ll* head;
}newll;

typedef struct graph{
    int V;
    newll* arr;
}Graph;

Graph* createGraph(int v)
{
    Graph* newgraph = (Graph*)malloc(sizeof(Graph));
    newgraph->V=v;
    
    newgraph->arr = (ll*)malloc(v*sizeof(ll));
    
    for(int i=0;i<v;i++)
    {
        newgraph->arr[i].head=NULL;
    }
    
    return newgraph;
}

void addEdge(Graph* g,int v1,int v2)
{
    ll* new_node1 = (ll*)malloc(sizeof(ll));
    new_node1->data = v2;
    new_node1->next = g->arr[v1].head;
    g->arr[v1].head = new_node1;
    
    ll* new_node2 = (ll*)malloc(sizeof(ll));
    new_node2->data=v1;
    new_node2->next = g->arr[v2].head;
    g->arr[v2].head = new_node2;
}

void printGraph(Graph* g)
{
    int n = g->V;
    int i;
    
    for(i=0;i<n;i++)
    {
        printf("For %d -> ",i);
        
        while(g->arr[i].head)
        {
            printf("%d ",g->arr[i].head->data);
            g->arr[i].head = g->arr[i].head->next;
        }
        printf("\n");
    }
}

int main()
{
    int V;
    printf("Enter no of vertices in graph\n");
    scanf("%d",&V);
    struct Graph* graph = createGraph(V); 
    
    int q;
    printf("Enter no of queries\n");
    scanf("%d",&q);
    
    for(int i=0;i<q;i++)
    {
        int a,b;
        printf("Enter two no's to form edge\n");
        scanf("%d %d",&a,&b);
        addEdge(graph, a, b);
    }

    printGraph(graph); 
}
