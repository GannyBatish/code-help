int countNodes(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return 1+left+right;
    }
    bool isCBT(Node* root,int index,int count)
    {
        if(root==NULL)
        {
            return true;
        }
        if(index>=count)
        {
            return false;
        }
        bool left=isCBT(root->left,2*index+1,count);
        bool right=isCBT(root->right,2*index+2,count);
        return (left && right);
    }
    bool isMaxOrder(Node* root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        if(root->left!=NULL && root->right==NULL)
        {
            return root->data>root->left->data;
        }
        else{
            bool left=isMaxOrder(root->left);
            bool right=isMaxOrder(root->right);
            bool cnd1=root->data>root->left->data;
            bool cnd2=root->data>root->right->data;
            return left && right && cnd1 && cnd2;
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int count=countNodes(tree);
        int index=0;
        if(isCBT(tree,index,count) && isMaxOrder(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }