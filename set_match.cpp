class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans(2);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                ans[0] = nums[i];
            }
        }

        // sum of all number in array exclude the duplicate..
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        sum -= ans[0];
        cout << sum << endl;


        // calculate the sum of all natural number..

        int sum_natural = (nums.size() * (nums.size() + 1))/2;

        cout << sum_natural << endl;

        ans[1] = sum_natural - sum;
        return ans; 
    }
};
