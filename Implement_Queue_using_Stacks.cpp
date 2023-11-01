#include <stack>

class MyQueue {
public:
    MyQueue() {
        
    }
    std::stack<int> st1, st2; // Create two stacks st1 and st2
    
    void push(int x) {
        // Transfer elements from st1 to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Push new element into st1
        st1.push(x);

        // Transfer elements back from st2 to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
       if (st1.empty()) {
           return -1; // Queue is empty
       }
       int ans = st1.top();
       st1.pop();
       return ans;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

// Example of usage:
// MyQueue* obj = new MyQueue();
// obj->push(x);
// int param_2 = obj->pop();
// int param_3 = obj->peek();
// bool param_4 = obj->empty();
