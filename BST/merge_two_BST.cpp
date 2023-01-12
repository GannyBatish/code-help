//Approach 1 
//T(n)-O(n+m)
// S(n)-O(n+m)
void inorder(TreeNode<int> * root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> merge(vector<int> arr1,vector<int> arr2)
{
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size())
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size())
    {
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}
TreeNode<int>* buildBSTbyInorder(vector<int> &ans,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode<int>* root=new TreeNode<int>(ans[mid]);
    root->left=buildBSTbyInorder(ans,s,mid-1);
    root->right=buildBSTbyInorder(ans,mid+1,e);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here.
    vector<int> inorder1,inorder2;
    inorder(root1,inorder1);
    inorder(root2,inorder2);
    vector<int> ans=merge(inorder1,inorder2);
    return buildBSTbyInorder(ans,0,ans.size()-1);
}