class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        // Step 1 calculate the sum of sum of array one by one and comparing it.
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            // Step 2 checking when adding element in sum it greater then it 
            // previous sum or not 
            maxi = max(maxi,sum); 

            // Step 3 checking sum is lesser then zero or not 
            // because we want to maximum sum that's why doing this one
            if(sum < 0){
                sum = 0; 
            }
        }
        return maxi;
    }
};
