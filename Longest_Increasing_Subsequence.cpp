class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        

        for(int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            auto it = lower_bound(arr.begin(), arr.end(), element);

            if(it == arr.end()){
                arr.push_back(element);
            }
            else{
                int index = it  - arr.begin();
                arr[index] = element;
            }
        }
        return arr.size();
    }
};

