void inorder(BinaryTreeNode*root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void preOrder(BinaryTreeNode* root,vector<int> in,int &index)
{
    if(root==NULL)
    {
        return;
    }
    root->data=in[index++];
    preOrder(root->left,in,index);
    preOrder(root->right,in,index);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
    vector<int> in;
    inorder(root,in);
    int i=0;
    preOrder(root,in,i);
    return root;
}