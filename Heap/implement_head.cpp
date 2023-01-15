#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap()
    {
        arr[0]=-1;
        size=0;
    }
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void insert(int val)
    {
        size=size+1;
        arr[size]=val;
        int i=size;
        while(i!=1)
        {
            if(arr[i]>arr[i/2])
            {
                swap(arr[i],arr[i/2]);
                i=i/2;
            }
            else{
                return;
            }
        }
    }
    void heapify(int i)
    {
        int largest=i;
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        if(leftIndex<=size && arr[i]<arr[leftIndex])
        {
            largest=leftIndex;
        }
        if(rightIndex<=size && arr[largest]<arr[rightIndex])
        {
            largest=rightIndex;
        }

        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            heapify(largest);
        }
    }
    void deleteFromHeap()
    {
        if(size==-1)
        {
            cout<<"Nothing to delete"<<endl;
        }
        arr[1]=arr[size];
        size--;
        heapify(1);
    }
    void printArr()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void lvlOrderTraversal()
    {
        queue<int> q;
        q.push(1);
        q.push(-1);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            if(i==-1)
            {
                cout<<endl;
                if(!q.empty())
                {
                    q.push(-1);
                }
            }
            else{
                cout<<arr[i]<<" ";
                if(2*i<=size)
                {
                    q.push(2*i);
                }
                if(2*i+1<=size)
                {
                    q.push(2*i+1);
                }
            }
        }
    }
};
int main()
{
    heap h;
    while(true)
    {
        int temp;
        cin>>temp;
        if(temp==-1)
        {
            break;
        }
        h.insert(temp);
    }
    h.lvlOrderTraversal();
    h.deleteFromHeap();
    h.lvlOrderTraversal();
    return 0;
}