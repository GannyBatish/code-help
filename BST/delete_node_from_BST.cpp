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


Node* minVal(Node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

Node* deleteFromBST(Node* root,int x)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==x)
    {
        //0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //1 child 
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!= NULL)
        {
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
        }
    }
    else if(root->data>x)
    {
        root->left=deleteFromBST(root->left,x);
    }
    else
    {
        root->right=deleteFromBST(root->right,x);
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
void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
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
                // cout<<curr->data<<" "; //for pre Order Traversal
                pre->right=curr;
                curr=curr->left;
            }
            else
            {
                pre->right=NULL;
                cout<<curr->data<<" ";   //for inorder Traversal
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
    // cout<<endl;
    // morrisTraversal(root);
    int del;
    cin>>del;
    root=deleteFromBST(root,del);
    levelOrderTraversal(root);
    inorder(root);
    return 0;
}