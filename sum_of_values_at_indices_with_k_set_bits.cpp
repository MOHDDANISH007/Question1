class Solution {
public:
    int isSet(int n){
        int count_set_bit = 0;
        while(n > 0){
           count_set_bit += n & 1; 
            n >>= 1;
        }
        return count_set_bit;
        
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(isSet(i) == k){
                sum += nums[i];
            }
        }
        return sum;
    }
};
