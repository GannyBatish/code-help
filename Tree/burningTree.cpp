class Solution {
  public:
    Node* createMapping(Node* root,int target,map<Node*,Node*>& nodeToParent)
    {
        queue<Node*> q;
        q.push(root);
        Node* ans=NULL;
        nodeToParent[root]=NULL;
        while(!q.empty())
        {
            Node*front=q.front();
            q.pop();
            if(front->data==target)
            {
                ans=front;
            }
            if(front->left)
            {
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            if(front->right)
            {
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        return ans;
    }
    int burnTime(Node* root,map<Node*,Node*>& nodeToParent)
    {
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root]=true;
        int ans=0;
        while(!q.empty())
        {
            bool flag=false;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* front=q.front();
                q.pop();
                if(front->left && !visited[front->left])
                {
                    flag=true;
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right])
                {
                    flag=true;
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag=true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                    
                }
            }
            if(flag==true)
            {
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> nodeToParent;
        Node* t=createMapping(root,target,nodeToParent);
        int ans=burnTime(t,nodeToParent);
        return ans;
    }
};