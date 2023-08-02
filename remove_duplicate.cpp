class Solution {
public:
    bool check(vector<int>& arr, int i) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
        return true;
    }
    
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            if (check(nums, i)) {
                ans.push_back(nums[i]);
            }
        }
        nums = ans;  // Update the input vector with the new values
        return ans.size();
    }
};
