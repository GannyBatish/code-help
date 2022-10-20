#include <bits/stdc++.h> 
void insertSort(stack<int> &s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    if(!s.empty() && s.top()<x)
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    insertSort(s,x);
    s.push(num);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty())
    {
        return;
    }
    int num=stack.top();
    stack.pop();
    sortStack(stack);
    insertSort(stack,num);
}