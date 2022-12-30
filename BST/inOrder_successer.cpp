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



    Node * inOrderPredessor(Node* root,Node* x)
    {
        Node* ans=NULL;
        while(root!=NULL)
        {
            if (temp2->key < key) {
                pre = temp2;
                temp2 = temp2->right;
            } 
            else
            {
                temp2 = temp2->left;
            }
        }
    }