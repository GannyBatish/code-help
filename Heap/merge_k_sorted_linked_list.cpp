class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
        priority_queue<Node*,vector<Node*>,compare> minHeap;
        if (k == 0) {
            return NULL;
        }
        for(int i=0;i<k;i++){
            if(arr[i]!=NULL){
                minHeap.push(arr[i]);
            }
        }
        Node* head=NULL;
        Node* tail=NULL;
        while(minHeap.size()>0){
            Node* top=minHeap.top();
            minHeap.pop();
            if(top->next!=NULL){
                minHeap.push(top->next);
            }
            if(head==NULL && tail==NULL){
                head=top;
                tail=top;
            }
            else{
                tail->next=top;
                tail=top;
            }
        }
        return head;
    }
};