#include <set>
#include <algorithm> // For std::max
#include <cmath>     // For std::abs

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> uniqueNums;

        // Populate set with unique elements from nums
        for (auto it : nums) {
            uniqueNums.insert(it);
        }

        int maxi = -1;

        // Iterate over uniqueNums to find maximum element meeting the condition
        for (auto element : uniqueNums) {
            if (uniqueNums.find(-element) != uniqueNums.end()) { // Check if -element exists in uniqueNums
                maxi = max(maxi, abs(element)); // Update maxi with the absolute value of element
            }
        }

        return maxi;
    }
};
