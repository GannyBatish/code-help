#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int maxDepth(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)
    {
        return -1;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return max(left,right)+1;
}