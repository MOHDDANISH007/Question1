class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;

        // sort the arrray..
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i=2; i<n; i+=3){
            if(nums[i] - nums[i-2] > k){
                return result;
            }
        }

        for(int i=2; i<nums.size(); i+=3){
            result.push_back({nums[i-2],nums[i-1], nums[i]});  
        }
        return result;

    }
};
