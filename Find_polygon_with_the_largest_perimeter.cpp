class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        sort(nums.begin(), nums.end());

        long long sum = 0;


        for(int it: nums){
            sum += it; // assuming that it is two sides..
        }


        for(int i=nums.size()-1; i>=2; i--){
            sum  -= nums[i]; // current on any element assuing it is third side and remove and checking "sum" of two side is greater then of third side  

            if(nums[i] < sum){
                return sum + nums[i];
            }
        }
        return -1;
    }
};
