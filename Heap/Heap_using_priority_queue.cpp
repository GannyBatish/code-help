#include<bits/stdc++.h>
using namespace std;
int main()
{
    //max-heap
    priority_queue<int> max_heap;
    max_heap.push(4);
    max_heap.push(5);
    max_heap.push(2);
    max_heap.push(3);
    cout<<max_heap.top()<<endl;
    max_heap.pop();
    cout<<max_heap.top()<<endl;
    cout<<max_heap.size()<<endl;
    if(max_heap.empty())
    {
        cout<<"Max Heap Priority Queue is Empty"<<endl;
    }
    else{
        cout<<"Max Heap Priority Queue is Not Empty"<<endl;
    }

    //Min Heap
    priority_queue<int,vector<int>,greater<int>> min_heap;
    min_heap.push(4);
    min_heap.push(5);
    min_heap.push(2);
    min_heap.push(3);
    cout<<min_heap.top()<<endl;
    min_heap.pop();
    cout<<min_heap.top()<<endl;
    cout<<min_heap.size()<<endl;
    if(min_heap.empty())
    {
        cout<<"Min Heap Priority Queue is Empty"<<endl;
    }
    else
        cout<<"Min Heap Priority Queue is NOt Empty"<<endl;
    {

    }
    return 0;
}