#include <vector>

class Solution {
public:
    void subset(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &dc, int index, int sum, int n) {
        if (sum == target) {
            res.push_back(dc);
            return;
        }
        if (index >= n || sum > target) {
            return;
        }
        
        // Include the current element
        sum += candidates[index];
        dc.push_back(candidates[index]);
        subset(candidates, target, res, dc, index, sum, n);
        
        // Exclude the current element
        sum -= candidates[index];
        dc.pop_back();
        subset(candidates, target, res, dc, index + 1, sum, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> dc;
        int index = 0;
        int sum = 0;
        int n = candidates.size();
        subset(candidates, target, res, dc, index, sum, n);
        return res;
    }
};

