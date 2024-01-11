#include <vector>

class Solution {
public:
    void solve(int n, vector<vector<int>>& ans, vector<int>& temp, int index, int k) {
        if (index > n) {
            return;
        }
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Include the current element in the combination
        temp.push_back(index);
        solve(n, ans, temp, index + 1, k);

        // Exclude the current element from the combination
        temp.pop_back();
        solve(n, ans, temp, index + 1, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
