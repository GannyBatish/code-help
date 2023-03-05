#include <bits/stdc++.h> 
class Node{
    public:
    int data;
    int i;
    int j;
    Node(int data,int i,int j){
        this->data=data;
        this->i=i;
        this->j=j;
    }
};
class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    priority_queue<Node*,vector<Node*>,compare> mini;
    for(int i=0;i<k;i++)
    {
        Node* temp=new Node(arr[i][0],i,0);
        mini.push(temp);
    }
    vector<int> ans;
    while(mini.size()>0)
    {
        Node* temp=mini.top();
        mini.pop();
        ans.push_back(temp->data);
        int i=temp->i;
        int j=temp->j;
        if(j+1<arr[i].size()){
            Node* next=new Node(arr[i][j+1],i,j+1);
            mini.push(next);
        }
    }
    return ans;
}
