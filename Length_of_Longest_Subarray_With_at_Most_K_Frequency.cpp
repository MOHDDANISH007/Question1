class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int ans = INT_MIN;
        int e = 0;

        for(int s=0,e=0; e<nums.size(); e++){
            mp[nums[e]]++;
            if(mp[nums[e]] > k){
                while(nums[s] != nums[e]){
                    mp[nums[s]]--;
                    s++;
                }
                mp[nums[s]]--;
                s++;
            }
            ans = max(ans, e-s+1);
        }
        return ans;
    }
};

