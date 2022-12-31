int solve(TreeNode<int> * root,int &i,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1)
    {
        return left;
    }
    i++;
    if(i==k)
    {
        return root->data;
    }
    return solve(root->right,i,k);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int i=0;
    return solve(root,i,k);
}




//simple approach idea by money batish equity-1.5%
void solve(BinaryTreeNode<int> * root,int &i,int k,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->left,i,k,ans);
    i++;
    if(i==k)
    {
        ans=root->data;
        return;
    }
    solve(root->right,i,k,ans);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int ans=-1;
    int i=0;
    solve(root,i,k,ans);
    return ans;
}