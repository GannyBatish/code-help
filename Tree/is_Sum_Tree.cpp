//Approach #1 Time Complexity O(n^2)
int sum(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return root->data;
        }
        int left=sum(root->left);
        int right=sum(root->right);
        return left+right+root->data;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL)
         {
             return true;
         }
         if(root->left==NULL && root->right==NULL)
         {
             return true;
         }
         bool left=isSumTree(root->left);
         bool right=isSumTree(root->right);
         bool cond=sum(root->left)+sum(root->right)==root->data;
         if(left && right && cond)
         {
             return true;
         }
         else
         {
             return false;
         }
    }


// Approach #2 Time Complexity O(n)
pair<bool,int> isSumFast(Node* root)
    {
        if(root==NULL)
        {
            return make_pair(true,0);
        }
        if(root->left==NULL && root->right==NULL)
        {
            return make_pair(true,root->data);
        }
        pair<bool,int> left=isSumFast(root->left);
        pair<bool,int> right=isSumFast(root->right);
        
        int leftSum=left.second;
        int rightSum=right.second;
        
        bool isLeftSumTree=left.first;
        bool isRightSumTree=right.first;
        bool cond=leftSum+rightSum==root->data;
        
        pair<bool,int> ans;
        if(isLeftSumTree && isRightSumTree && cond)
        {
            ans.first=true;
            ans.second=2*root->data;
        }
        else
        {
            ans.second=false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumFast(root).first;
    }