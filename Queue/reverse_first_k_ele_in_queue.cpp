void reverse(queue<int> &q,int k,int i=0)
{
    if(i==k)
    {
        return;
    }
    int ele=q.front();
    q.pop();
    reverse(q,k,i+1);
    q.push(ele);
}
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    reverse(q,k);
    int t=q.size()-k;
    while(t--)
    {
        int ele=q.front();
        q.pop();
        q.push(ele);
    }
    return q;
}