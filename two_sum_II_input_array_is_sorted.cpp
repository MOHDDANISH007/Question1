class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> ans;
        int start = 0;
        int end = numbers.size()-1;
        while(start <= end){
            int sum = numbers[start] + numbers[end];
            if(sum > target){
                end--;
            }
            else if(sum < target){
                start++;
            }
            else{
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                start++;
                end--;
                return ans;
            }
        }
        return ans;
    }
};
