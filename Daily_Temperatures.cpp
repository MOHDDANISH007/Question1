#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                result[i] = 0;
            } else {
                int days = st.top() - i;
                result[i] = days;
            }

            st.push(i);
        }

        return result;
    }
};
