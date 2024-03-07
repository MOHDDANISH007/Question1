class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for(auto it:nums){
            if(it >= k){
               return cnt;
            }
            cnt++;
        }
        return cnt;
    }
};
