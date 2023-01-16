#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void buildHeap(int arr[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}
int main()
{
    int arr[10] = {-1, 35, 75, 10, 60, 90, 30, 85, 50,70};
    int n = 9;
    buildHeap(arr,n);
    heapSort(arr,n);
    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}