void inorder(Node* root,vector<int>& ans)
  {
      if(root==NULL)
        return;
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
  void maxHeap(Node* root,vector<int> &in,int &i)
  {
      if(root==NULL)
        return;
      root->data=in[i--];
      maxHeap(root->right,in,i);
      maxHeap(root->left,in,i);
  }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> in;
        inorder(root,in);
        int i=in.size()-1;
        maxHeap(root,in,i);
    } 