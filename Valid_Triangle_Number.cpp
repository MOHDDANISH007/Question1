class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int sum = nums[i] + nums[j];

                int starting = j+1;
                int ending   = nums.size()-1;


                while(starting <= ending){
                    int mid = starting + (ending - starting) / 2;

                    if(nums[mid] < sum){
                        starting = mid + 1;
                    }
                    else{
                        ending  = mid - 1;
                    }
                }  
                // how much valid pair in that range .... 

                ans += (ending - j);
            }
        }
        return ans;
    }
};
