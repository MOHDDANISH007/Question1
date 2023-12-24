#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> numberGame(std::vector<int>& nums) {
        std::vector<int> ans;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i += 2) {
            int alice = nums[i];
            int bob = nums[i + 1];
            ans.push_back(bob);
            ans.push_back(alice);
        }

        return ans;
    }
};

