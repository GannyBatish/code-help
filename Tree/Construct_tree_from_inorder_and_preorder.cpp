Node* solve(int in[],int pre[],int &index,int inStart,int inEnd,int n,map<int,int> &map)
    {
        if(index>=n || inStart>inEnd)
        {
            return NULL;
        }
        int ele=pre[index++];
        Node* root=new Node(ele);
        int pos=map[ele];
        root->left=solve(in,pre,index,inStart,pos-1,n,map);
        root->right=solve(in,pre,index,pos+1,inEnd,n,map);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index=0;
        map<int,int> map;
        for(int i=0;i<n;i++)
        {
            map[in[i]]=i;
        }
        Node* root=solve(in,pre,index,0,n-1,n,map);
        return root;
    }