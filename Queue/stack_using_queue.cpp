#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q1,q2;
   public:
    Stack() {
        // Implement the Constructor.
    }
    /*----------------- Public Functions of Stack -----------------*/
    private:
    void swapqueue(queue<int> &q1,queue<int> &q2)
    {
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    public:
    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.empty())
        {
            return true;
        }
        return false;
    }
    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty())
        {
            int val=q1.front();
            q1.pop();
            q2.push(val);
        }
        swapqueue(q1,q2);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty())
        {
            return -1;
        }
        int val=q1.front();
        q1.pop();
        return val;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};