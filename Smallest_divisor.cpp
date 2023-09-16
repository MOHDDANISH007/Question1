class Solution {
public:
     
    int max_element(vector<int> nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }

    int sum(vector<int> nums, int mid){
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += ceil(double(nums[i]) / double(mid));
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low  = 1;
        // step 1 = finding max_element in the array where me make out search space.
        int high = max_element(nums);
        int ans = -1;
        while(low <= high){
            // step 2 = finding the middle element in the array.
            int mid = low + (high - low) / 2;
            if(sum(nums, mid) <= threshold){
                // after checking the array element is lesser then our threshold
                // value for mid value which working as a divisor for all the element
                // in the array and it will change upto till not get the better answer. 
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1; 
            }
        }
        // step 3 = return our answer.
        return ans;
    }
};
