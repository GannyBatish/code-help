class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(TreeNode<int>* root,int &ans)
{
    if(root==NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);
    
    info data;
    data.maxi=max(root->data,right.maxi);
    data.mini=min(root->data,left.mini);
    data.size=left.size+right.size+1;
    if(left.isBST && right.isBST && root->data>left.maxi && root->data<right.mini)
    {
        data.isBST=true;
    }
    else{
        data.isBST=false;
    }
    if(data.isBST)
    {
        ans=max(ans,data.size);
    }
    return data;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize=0;
    info result=solve(root,maxSize);
    return maxSize;
}