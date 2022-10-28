#include <bits/stdc++.h> 
void solve(stack<int> &s, int size,int count)
{
    if(count==size/2)
    {
        s.pop();
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,size,count+1);
    s.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
    int count=0;
    solve(inputStack,N,count);
}