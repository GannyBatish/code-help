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




//Approach 2
// T(n)- O(n+m);
// S(n)- O(h1+h2)
void convertBSTtoDLL(TreeNode<int> *root,TreeNode<int>* &head)
{
    if(root==NULL)
    {
        return;
    }
    convertBSTtoDLL(root->right,head);
    
    root->right=head;
    if(head!=NULL)
    {
        head->left=root;
    }
    head=root;
    
    convertBSTtoDLL(root->left,head);
}
TreeNode<int>* mergeTwoDLL(TreeNode<int>* head1,TreeNode<int>* head2)
{
    TreeNode<int>* head=NULL;
    TreeNode<int>* tail=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            if(head==NULL && tail==NULL)
            {
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL && tail==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL)
    {
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL)
    {
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}
int countNodes(TreeNode<int>* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->right;
    }
    return count;
}
TreeNode<int>* convertDLLtoBST(TreeNode<int>* &head,int n)
{
    if(n<=0 || head==NULL)
    {
        return NULL;
    }
    TreeNode<int>* left=convertDLLtoBST(head,n/2);
    TreeNode<int>* root=head;
    root->left=left;
    head=head->right;
    root->right=convertDLLtoBST(head,n-n/2-1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here.
    TreeNode<int>* head1=NULL;
    TreeNode<int>* head2=NULL;

    convertBSTtoDLL(root1,head1);
    head1->left=NULL;
    
    convertBSTtoDLL(root2,head2);
    head2->left=NULL;
    
    TreeNode<int>* head=mergeTwoDLL(head1,head2);
    return convertDLLtoBST(head,countNodes(head));
}