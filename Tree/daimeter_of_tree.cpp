class Solution {
  private:
    int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root==NULL)
        {
            return 0;
        }
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right)+1;
        return max(op1,max(op2,op3));
    }
};