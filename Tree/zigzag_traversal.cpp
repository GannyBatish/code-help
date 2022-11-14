//my Approach using stack
vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight=true;
    	vector<int> ans;
    	stack<Node*> s;
    	while(!q.empty())
    	{
    	    if(leftToRight)
    	    {
    	        int size=q.size();
    	        for(int i=0;i<size;i++)
    	        {
    	            Node* temp=q.front();
    	            q.pop();
    	            ans.push_back(temp->data);
    	            if(temp->left)
    	            {
    	                q.push(temp->left);
    	            }
    	            if(temp->right)
    	            {
    	                q.push(temp->right);
    	            }
    	        }
    	        leftToRight=false;
    	    }
    	    else
    	    {
    	        
    	        int size=q.size();
    	        for(int i=0;i<size;i++)
    	        {
    	            Node* temp=q.front();
    	            q.pop();
    	            s.push(temp);
    	            if(temp->left)
    	            {
    	                q.push(temp->left);
    	            }
    	            if(temp->right)
    	            {
    	                q.push(temp->right);
    	            }
    	        }
    	        while(!s.empty())
    	        {
    	            Node* temp=s.top();
    	            ans.push_back(temp->data);
    	            s.pop();
    	        }
    	        leftToRight=true;
    	    }
    	}
    	return ans;
    }

