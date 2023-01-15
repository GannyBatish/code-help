#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    if(leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    if(rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void lvlOrderTraversal(int arr[],int size)
{
    queue<int> q;
    q.push(1);
    q.push(-1);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (i == -1)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(-1);
            }
        }
        else
        {
            cout << arr[i] << " ";
            if (2 * i <= size)
            {
                q.push(2 * i);
            }
            if (2 * i + 1 <= size)
            {
                q.push(2 * i + 1);
            }
        }
    }
}
int main()
{
    int arr[10] = {-1, 35, 75, 10, 60, 90, 30, 85, 50,70};
    int n = 9;
    //i=n/2 because leaf nodes start from n/2+1 to nth node
    //so we want to heapify from the reverse direction
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    lvlOrderTraversal(arr,n);
    return 0;
}