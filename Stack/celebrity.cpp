#include <bits/stdc++.h> 
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B); 
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }
    while(s.size()!=1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(knows(a,b))
        {
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int celebrity=s.top();
    int zeroCount=0;
    for(int i=0;i<n;i++)
    {
        if(M[celebrity][i]==0)
        {
            zeroCount++;
        }
    }
    if(zeroCount!=n)
    {
        return -1;
    }
    int oneCount=0;
    for(int i=0;i<n;i++)
    {
        if(M[i][celebrity]==1)
        {
            oneCount++;
        }
    }
    if(oneCount!=n-1)
    {
        return -1;
    }
    return celebrity;
}