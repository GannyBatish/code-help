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