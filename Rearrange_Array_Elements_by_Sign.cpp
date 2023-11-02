class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // step 1 creating the 3 vector..
        vector<int> po, ne, ans;
        // positive vector, negative vector and ans vector..

        for(int i=0; i<nums.size(); i++){
            // step 2 checking weather the given number is positive or negative..

            if(nums[i] > 0){
                po.push_back(nums[i]);
            }
            else{
                ne.push_back(nums[i]);
            }
        }
        // step 3 = push my all positive and negative value in alternate ways..   
        for(int i=0; i<po.size(); i++){
            ans.push_back(po[i]);
            ans.push_back(ne[i]);
        }
        // step 3 return your's answer..
        return ans;
    }
};
