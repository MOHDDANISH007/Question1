class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        int s  = 0, e=0;
        int result = 0;

        // computing for Strictly Increasing subarray.

        while(s < n){// shrinking the windows
            e=s;
            // expanding the windows
            while(e<n && (s==e || nums[e] > nums[e-1])){
                e++;
            }
            result = max(result, e - s);
            // s++;
            s = e;
        }
        s=0;


        // computing for Strictly decreasing subarray

       while(s < n){// shrinking the windows
            e=s;
            // expanding the windows
            while(e<n && (s==e || nums[e] < nums[e-1])){
                e++;
            }
            result = max(result, e - s);
            // s++;
            s =e;
        }
        return result;
    }
};
