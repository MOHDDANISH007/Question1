class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            result += nums[i];
            if(result == 0){
                cnt++;
            }
        }
        return cnt;
    }
};	
