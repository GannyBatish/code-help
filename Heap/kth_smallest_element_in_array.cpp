int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> q;
        for(int i=0;i<k;i++)
        {
            q.push(arr[i]);
        }
        for(int i=k;i<=r;i++)
        {
            if(arr[i]<q.top())
            {
                q.pop();
                q.push(arr[i]);
            }
        }
        return q.top();
    }