#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	// Write your code here.
    long long ans=0;
    for(int i=0;i<=n-k;i++)
    {
        int mini=arr[i];
        int maxi=arr[i];
        for(int j=i+1;j<i+k;j++)
        {
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
        }
        ans+=maxi+mini;
    }
    return ans;
}
