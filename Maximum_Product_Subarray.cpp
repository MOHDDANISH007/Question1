class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int product = 1;
        // This for left half 
        for(int i=0; i<nums.size(); i++){
            product *= nums[i];
            maxi = max(maxi,product);
            if(product == 0){
                product = 1;
            }
        }

        // This is for Right half
        int pro = 1;
        for(int i=nums.size()-1; i>=0; i--){
            pro *= nums[i];
            maxi = max(pro,maxi);
            if(pro == 0){
                pro = 1;
            }
        }
        return maxi;
    }
};
