//slow appraoch Time Complexity O(N^2)
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



//fast appraoch Time Complexity O(N)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> diaFast(Node* root)
    {
        if(root==NULL)
        {
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=diaFast(root->left);
        pair<int,int> right=diaFast(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        
        pair<int,int> p;
        p.first=max(op1,max(op2,op3));
        p.second=max(left.second,right.second)+1;
        return p;
    }
    int diameter(Node* root) {
        // Your code here
        return diaFast(root).first;
    }
};