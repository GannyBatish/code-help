#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};
class stack
{
    public:
    Node* top=NULL;
    void push(int val)
    {
        Node* newNode=new Node(val);
        if(top==NULL)
        {
            top=newNode;
            return;
        }
        newNode->next=top;
        top=newNode;
    }
    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        top=top->next;
    }
    int peek()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    bool empty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.peek()<<endl;
    // cout<<s.peek()<<endl;
    // s.pop();
    s.pop();         
    s.pop();  
    s.pop();  
    s.pop();  
    s.pop();
    // cout<<s.peek()<<endl;
    if(s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"stack is not empty"<<endl;
    }
    return 0;
}