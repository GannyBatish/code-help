void inorder(TreeNode<int>* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> ans;
    inorder(root,ans);
    int n=ans.size();
    TreeNode<int>* head=new TreeNode<int>(ans[0]);
    TreeNode<int>* tail=head;
    for(int i=1;i<n;i++)
    {
        TreeNode<int>* temp=new TreeNode<int>(ans[i]);
        tail->right=temp;
        tail=temp;
    }
    return head;
}