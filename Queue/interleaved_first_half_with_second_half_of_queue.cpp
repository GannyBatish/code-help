//using another queue
#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    queue<int> q1;
    int n=q.size();
    int i=0;
    while(i<n/2){
        int val=q.front();
        q.pop();
        q1.push(val);
        i++;
    }
    
    while(!q1.empty()){
        int val=q1.front();
        q1.pop();
        q.push(val);
        val=q.front();
        q.pop();
        q.push(val);
    }
}


// using stack
#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    stack<int> s;
    int n=q.size();
    int i=0;
    while(i<n/2)
    {
        int val=q.front();
        q.pop();
        s.push(val);
        i++;
    }
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);
    }
    i=0;
    while(i<n/2)
    {
        int val=q.front();
        q.pop();
        q.push(val);
        i++;
    }
    i=0;
    while(i<n/2)
    {
        int val=q.front();
        q.pop();
        s.push(val);
        i++;
    }
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        q.push(val);
        val=q.front();
        q.pop();
        q.push(val);
    }
}