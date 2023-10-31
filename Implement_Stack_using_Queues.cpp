#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1, q2;

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        return;
    }
    
    int pop() {
        if (q1.empty()) {
            return -1;
        } else {
            int frontElement = q1.front();
            q1.pop();
            return frontElement;
        }
    }
    
    int top() {
        if (q1.empty()) {
            return -1; // Or throw an exception for an empty stack
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

