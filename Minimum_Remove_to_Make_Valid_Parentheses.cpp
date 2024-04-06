#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.empty()) {
            return "";
        }
        stack<int> st;
        int length = s.length();
        // Finding the index of invalid parentheses 
        for (int i = 0; i < length; i++) {
            char ch = s[i];
            if (ch == '(') {
                // Push the index of '(' to the stack
                st.push(i);
            } else if (ch == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    // '(' found, pop matching '(' from the stack
                    st.pop();
                } else {
                    // Invalid ')' or stack is empty, push the index to the stack
                    st.push(i);
                }
            }
        }

        // Create the result string
        string ans = "";
        for (int i = length-1; i >= 0; i--) {
            // Skip characters at indices stored in stack
            if (!st.empty() && st.top() == i) {
                st.pop();
                continue;
            }
            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
