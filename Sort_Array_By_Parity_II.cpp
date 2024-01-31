class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd, ans(nums.size(), 0);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        int even_index = 0, odd_index = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans[i] = even[even_index++];
            } else {
                ans[i] = odd[odd_index++];
            }
        }
        return ans;
    }
};
