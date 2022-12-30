#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertInBST(Node* root,int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
    }
    if(data<root->data)
    {
        root->left=insertInBST(root->left,data);
    }
    else
    {
        root->right=insertInBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root)
{
    while(true)
    {
        int data;
        cin>>data;
        if(data==-1)
        {
            break;
        }
        root=insertInBST(root,data);
    }
}
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void morrisTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Node* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else
        {
            Node* pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr)
            {
                pre=pre->right;
            }
            if(pre->right==NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }
            else
            {
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}
int main()
{
    Node* root=NULL;
    takeInput(root);
    levelOrderTraversal(root);
    inorder(root);
    cout<<endl;
    morrisTraversal(root);
    return 0;
}