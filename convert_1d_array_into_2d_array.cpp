#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            
            int fr = mp[nums[i]];

            // checking duplicate elements..
            if (fr == result.size()) {
                // adding extra row;
                //result.push_back({});
                result.push_back();
            }
            result[fr].push_back(nums[i]);
            mp[nums[i]]++;
        }
        return result;
    }
};
