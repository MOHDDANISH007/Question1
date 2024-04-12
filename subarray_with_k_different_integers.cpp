class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mpp;
        int j = 0, i = 0;
        while (j < n) {
            mpp[nums[j]]++;
            while ( mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            ans += j - i +1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
