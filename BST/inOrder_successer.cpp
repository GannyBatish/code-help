Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* ans = NULL;
        
        while(root != NULL){
            if(root->data > x->data){
                ans = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return ans;
    }