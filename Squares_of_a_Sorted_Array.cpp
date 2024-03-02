class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);

        for(int i=0; i<nums.size(); i++){
            int element = nums[i];
            ans[i] = element * element;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
