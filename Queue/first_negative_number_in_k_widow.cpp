#include<queue>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	// Write your code here.
    vector<int> ans;
    deque<int> q;
    for(int i=0;i<k;i++)
    {
        if(arr[i]<0)
        {
            q.push_back(i);
        }
    }
    if(q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(arr[q.front()]);
    }
    for(int i=k;i<n;i++)
    {
        if(!q.empty() && i-q.front()>=k)
        {
            q.pop_front();
        }
        if(arr[i]<0)
        {
            q.push_back(i);
        }
        if(q.empty()){
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}