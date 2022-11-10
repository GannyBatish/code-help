#include <bits/stdc++.h> 
class NQueue{
public:
    // Initialize your data structure.
    int freespot;
    int *arr;
    int *next;
    int *front;
    int *rear;
    NQueue(int n, int s){
        // Write your code here.
        front=new int[n];
        rear=new int[n];
        for(int i=0;i<n;i++)
        {
            front[i]=-1;
            rear[i]=-1;
        }
        arr=new int[s];
        next=new int[s];
        for(int i=0;i<s;i++)
        {
            next[i]=i+1;
        }
        next[s-1]=-1;
        freespot=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
        if(freespot==-1)
        {
            return false;
        }
        int index=freespot;
        freespot=next[index];
        if(front[m-1]==-1)
        {
            front[m-1]=index;
        }
        else
        {
            next[rear[m-1]]=index;
        }
        next[index]=-1;
        rear[m-1]=index;
        arr[index]=x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        if(front[m-1]==-1)
        {
            return -1;
        }
        int index=front[m-1];
        front[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};