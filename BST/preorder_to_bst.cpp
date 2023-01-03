TreeNode<int>* solve(vector<int>& pre,int mini,int maxi,int &i)
{
    if(i>=pre.size())
        return NULL;
    
    if(pre[i]<mini || pre[i]>maxi)
        return NULL;
    
    TreeNode<int>* root=new TreeNode<int>(pre[i++]);
    root->left=solve(pre,mini,root->data,i);
    root->right=solve(pre,root->data,maxi,i);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return solve(preOrder,INT_MIN,INT_MAX,i);
}