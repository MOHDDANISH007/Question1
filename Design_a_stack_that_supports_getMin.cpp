#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
public:
    stack<int> arr, min_arr;

    void push(int val) {
        arr.push(val);
        if (min_arr.empty() || val <= min_arr.top()) {
            min_arr.push(val);
        } else {
            min_arr.push(min_arr.top());
        }
    }

    void pop() {
        arr.pop();
        min_arr.pop();
    }

    int top() {
        if(arr.empty() == true){
            return -1;
        } else {
            return arr.top();
        }
    }

    int getMin() {
        return min_arr.top();
    }
};
