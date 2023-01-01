void solve(BinaryTreeNode<int> * root,int &i,int k,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->right,i,k,ans);
    i++;
    if(i==k)
    {
        ans=root->data;
        return;
    }
    solve(root->left,i,k,ans);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int ans=-1;
    int i=0;
    solve(root,i,k,ans);
    return ans;
}