#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cntOperation = 0;
        // map<int, bool> mp;

        // // Sort the array first
        // sort(nums.begin(), nums.end());

        // for (int i = 0; i < nums.size(); i++) {
        //     int element = nums[i];
        //     // If the element is already in the map, find the next unique element
        //     while (mp.find(element) != mp.end()) {
        //         element += 1;
        //         cntOperation++;
        //     }
        //     // Mark the element as seen
        //     mp[element] = true;
        // }
        // return cntOperation;

        sort(begin(nums),end(nums));

        for(int i=1; i<nums.size(); i++){
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                cntOperation += increment;
            }
        }
        return cntOperation;
    }
};
