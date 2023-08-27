class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int mini = INT_MAX;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[s]){
                mini = min(nums[s],mini);
                s = mid + 1;
            }
            else if(nums[mid] <= nums[e]){
                // searching in Right part
                mini = min(nums[mid], mini);
                e =  mid - 1; 
            }
        }
        return mini;
    }
};
