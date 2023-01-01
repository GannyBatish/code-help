//love babbar approach
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pre=-1;
    int succ=-1;
    BinaryTreeNode<int>* temp=root;
    while(temp->data!=key)
    {
        if(temp->data>key)
        {
            succ=temp->data;
            temp=temp->left;
        }
        else
        {
            pre=temp->data;
            temp=temp->right;
        }
    }
    BinaryTreeNode<int>* leftTree=temp->left;
    BinaryTreeNode<int>* rightTree=temp->right;
    while(leftTree!=NULL)
    {
        pre=leftTree->data;
        leftTree=leftTree->right;
    }
    while(rightTree!=NULL)
    {
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    return make_pair(pre,succ);
}




//my approach
int inorderPred(BinaryTreeNode<int>* root,int key)
{
    int ans=-1;
    while(root!=NULL)
    {
        if(root->data<key)
        {
            ans=root->data;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return ans;
}
int inorderSucc(BinaryTreeNode<int>* root,int key)
{
    int ans=-1;
    while(root!=NULL)
    {
        if(root->data>key)
        {
            ans=root->data;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return ans;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pre=inorderPred(root,key);
    int succ=inorderSucc(root,key);
    return make_pair(pre,succ);
}