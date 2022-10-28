#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int n;
    int front;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        this->n=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //check if queue is full
        if(rear==(front-1)%n)
        {
            return false;
        }
        //check if queue is empty
        if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else
        {
            //to make queue circular
            rear=(rear+1)%n;
        }
        //enqueuing element in queue
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check if queue is empty
        if(front==-1 && rear==-1)
        {
            return -1;
        }
        int ans=arr[front];
        if(front==rear)
        {
            //if queue has only one element in it
            front=rear=-1;
        }
        else
        {
            //to make queue circular
            front=(front+1)%n;
        }
        return ans;
    }
};