#include<iostream>
using namespace std;
class stack
{
    public:
    int* arr;
    int size;
    int top;
    stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int ele)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=ele;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool empty()
    {
        if(top>=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
int main()
{
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.peek()<<endl;
    s.push(6);
    s.pop();    
    s.pop();    
    s.pop();
    cout<<s.peek()<<endl;    
    s.pop();
    if(s.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}