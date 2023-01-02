void inorder(TreeNode<int>* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int>* inorder_to_balanced_bst(vector<int>& ans,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode<int>* root=new TreeNode<int>(ans[mid]);
    root->left=inorder_to_balanced_bst(ans,s,mid-1);
    root->right=inorder_to_balanced_bst(ans,mid+1,e);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> in;
    inorder(root,in);
    return inorder_to_balanced_bst(in,0,in.size()-1);
}