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
    h.insert(60);
    h.insert(55);
    h.insert(33);
    h.insert(75);
    h.insert(90);
    h.insert(30);
    h.insert(65);
    h.insert(40);
    h.insert(15);
    h.insert(100);
    h.printArr();
    h.lvlOrderTraversal();
    return 0;
}