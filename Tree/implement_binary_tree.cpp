#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
class Tree
{
    public:
    node* root=NULL;
    node* buildTree(node* root)
    {
        cout<<"Enter a data "<<endl;
        int data;
        cin>>data;
        root=new node(data);
        if(data==-1)
        {
            return NULL;
        }
        cout<<"Enter a data in left of "<<data<<" : "<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter a data in right of "<<data<<" : "<<endl;
        root->right=buildTree(root->right);
        return root;
    }
    void levelOrderTraversal()
    {
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            node* temp=q.front();
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
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    void reverseLevelOrderTraversal()
    {
        queue<node*> q;
        stack<node*> s;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            node* temp=q.front();
            q.pop();
            s.push(temp);
            if(temp==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if(temp->right)
                {
                    q.push(temp->right);
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
            }
        }
        while(!s.empty())
        {
            node* temp=s.top();
            s.pop();
            if(temp==NULL)
            {
                cout<<endl;
            }
            else
            {
                cout<<temp->data<<" ";
            }
        }
    }
    void inorderTraversal(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
    void preorderTraversal(node* root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
};
int main()
{
    //    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Tree t;
    t.root=t.buildTree(t.root);
    t.levelOrderTraversal();
    cout<<"Reverse Order Traversal is : "<<endl;
    t.reverseLevelOrderTraversal();
    cout<<endl;
    cout<<endl;
    cout<<"INORDER TRAVERSAL : ";
    t.inorderTraversal(t.root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL : ";
    t.preorderTraversal(t.root);
    // cout<<endl;
    // cout<<"POSTORDER TRAVERSAL : ";
    // t.postorderTraversal(t.root);
    // cout<<endl;
    return 0;
}