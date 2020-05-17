#include <iostream>
#include<climits>
using namespace std;

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap 
{ 
    int *heap; 
    int size;
    int curr_size;
    
    public: 
        MinHeap(int n)
        {
            size=n;
            curr_size=0;
            heap = new int[n];
        }
        void minHeapify(int i)
        {
            int lchild = i*2+1;
            int rchild = i*2+2;
            if(lchild<curr_size||rchild<curr_size)
            {
                if(heap[i]>heap[lchild]||heap[i]>heap[rchild])
                {
                    if(heap[lchild]<heap[rchild])
                    {
                        swap(&heap[lchild],&heap[i]);
                        minHeapify(lchild);
                    }
                    else
                    {
                        swap(&heap[rchild],&heap[i]);
                        minHeapify(rchild);
                    }
                }
            }
        }
        void insertHeap(int val)
        {
            if(size==curr_size)
            {
                cout<<"Heap Full\n";
                return;
            }
            
            heap[curr_size]=val;
            curr_size++;
            int i;
            
            for(i=curr_size-1;i!=0&&heap[(i-1)/2]>heap[i];i=(i-1)/2)
            {
                swap(&heap[i],&heap[(i-1)/2]);
            }
            cout<<"Inserted "<<val<<" to MinHeap\n";
        }
        void changeVal(int i, int new_val) 
        { 
            heap[i] = new_val; 
            for(;i!=0&&heap[(i-1)/2]>heap[i];i=(i-1)/2) 
            { 
               swap(&heap[i], &heap[(i-1)/2]);
            } 
        } 
        int deleteMin()
        {
            if(curr_size<=0)
            {
                return INT_MAX;
            }
            if(curr_size==1)
            {
                curr_size--;
                return heap[curr_size];
            }
            
            int root = heap[0];
            curr_size--;
            heap[0]=heap[curr_size];
            minHeapify(0);
            return root;
        }
        int getMin()
        {
            return heap[0];
        }
  
    
}; 

int main()
{
    cout<<"## MinHeap ##\n";
    int n;
    cout<<"Enter capacity of Heap\n";
    cin>>n;
    
    cout<<"Enter 1 to insert number to Heap\n";
    cout<<"Enter 2 to delete minimum number from Heap\n";
    cout<<"Enter 3 to get minimum number in Heap\n";
    cout<<"Enter -1 or any other key to exit\n";
    
    MinHeap minHp(n);
    
    while(true)
    {
        int option;
        cin>>option;
        
        if(option==1)
        {
            int val;
            cout<<"Enter value to insert to Heap\n";
            cin>>val;
            minHp.insertHeap(val);
            
        }
        else if(option==2)
        {
            int minn = minHp.deleteMin();
            
            if(minn==INT_MAX)
            {
                cout<<"Heap is Empty\n";
            }
            else
            {
                cout<<"Deleted minimum value "<<minn<<" from MinHeap\n";
            }
        }
        else if(option==3)
        {
            cout<<"Minimum number in Heap is "<<minHp.getMin()<<endl;
        }
        else
        {
            cout<<"Exit";
            break;
        }
    }

    
    return 0;
}
