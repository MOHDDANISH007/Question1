#include <stack>

class MyQueue {
public:
    std::stack<int> input, output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty() == true){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()) {
            return -1; // Queue is empty
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()) {
            return -1; // Queue is empty
        }
        return output.top();
    }

    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

// Your MyQueue object will be instantiated and called as such:
// MyQueue* obj = new MyQueue();
// obj->push(x);
// int param_2 = obj->pop();
// int param_3 = obj->peek();
// bool param_4 = obj->empty();
