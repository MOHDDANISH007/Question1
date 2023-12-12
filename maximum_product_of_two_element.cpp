class Solution {
public:
    int maxProduct(vector<int>& nums) {


        // tc o(1)

        int size = nums.size();


        sort(nums.begin(),nums.end());

        return (nums[size-1] - 1) * (nums[size-2] - 1);


        
        // int maxi_1 = INT_MIN;
        // int maxi_2 = INT_MIN; 

        // int size = nums.size();

        // // find 1st and 2nd largest element in the array


        // for(int i=0; i<=size; i++){
        //     if(nums[i] > maxi_1){
        //         maxi_2 = maxi_1;
        //         maxi_1 = nums[i];
        //     }
        //     else if(nums[i] > maxi_2){
        //         maxi_2 = nums[i];
        //     }
        // }

        // return (maxi_1 - 1) * (maxi_2 -1);




        // brute force approach...

        // sort(nums.begin(), nums.end());

        // int maxi = INT_MIN;
        // int n = nums.size();

        // for(int i=0; i<=n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         maxi = max(maxi,(nums[i]-1)*(nums[j]-1));
        //     }
        // }
        // return maxi;
    }
};
