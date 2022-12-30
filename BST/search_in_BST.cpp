//T(N)- O(Log N)
//S(N)- O(Log N)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    if(root->data>x)
    {
        return searchInBST(root->left,x);
    }
    return searchInBST(root->right,x);
}




//T(N)-O(log N)
//S(N)-O(1)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> *temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            return true;
        }
        if(temp->data>x)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return false;
}