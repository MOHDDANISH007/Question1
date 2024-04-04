#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxDepth(string s) {
        if (s.empty()) {
            return 0;
        }

        stack<char> st;
        int depth = 0;
        int ans = 0;

        for (char ch : s) {
            st.push(ch);

            if (ch == '(') {
                depth++;
            }
            else if (ch == ')') {
                depth--;
            }
            ans = max(ans, depth);
        }
        return ans;
    }
};

