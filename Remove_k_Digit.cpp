#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> l_To_r;
        
        // Edge case: If k is non-positive, return the number itself
        if (k <= 0) {
            return num;
        }
        
        int length = num.size();
        for (int i = 0; i < length; i++) {
            // Pop digits from stack while the current digit is smaller than the top of the stack
            while (!l_To_r.empty() && k > 0 && num[i] < l_To_r.top()) {
                l_To_r.pop();
                k--;
            }
            // Skip leading zeros
            if (l_To_r.empty() && num[i] == '0') {
                continue;
            }
            l_To_r.push(num[i]);
        }
        
        // Pop remaining digits from stack to remove k digits
        while (k > 0 && !l_To_r.empty()) {
            l_To_r.pop();
            k--;
        }
        
        // Construct the answer string
        string ans = "";
        while (!l_To_r.empty()) {
            ans += l_To_r.top();
            l_To_r.pop();
        }
        
        // If the resulting string is empty, return "0"
        reverse(ans.begin(), ans.end());
        if (ans.empty()) {
            return "0";
        }
        
        return ans;
    }
};

