#include <vector>

class Solution {
public:
    void subset(int n, int k, vector<vector<int>>& ans, vector<int>& dc, int index) {
        if (dc.size() == k) {
            ans.push_back(dc);
            return;
        }
        if (index > n) {
            return;
        }

        // Include the current number
        dc.push_back(index);

        // starting backtracking here...
        subset(n, k, ans, dc, index + 1);

        // Exclude the current number
        dc.pop_back();
        subset(n, k, ans, dc, index + 1);

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> dc;
        int index = 1;
        subset(n, k, ans, dc, index);
        return ans;
    }
};
