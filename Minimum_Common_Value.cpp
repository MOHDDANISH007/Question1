class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        for(auto it:nums2){
            mp[it]++;
        }

        for(auto it:nums1){
            if(mp.find(it) != mp.end()){
                ans = min(ans, it);
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
