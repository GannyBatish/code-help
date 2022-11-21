private:
    void solve(Node* root,int k,vector<int> ans,int &count)
    {
        if(root==NULL)
            return;

        ans.push_back(root->data);
        solve(root->left,k,ans,count);
        solve(root->right,k,ans,count);
        
        int sum=0;
        int n=ans.size();
        for(int i=n-1;i>=0;i--)
        {
            sum+=ans[i];
            if(sum==k)
            {
                count++;
            }
        }
        ans.pop_back();
    }
  public:
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> ans;
        int count=0;
        solve(root,k,ans,count);
        return count;
    }