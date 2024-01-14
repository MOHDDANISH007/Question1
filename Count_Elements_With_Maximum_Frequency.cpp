#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;

        for (auto num : nums) {
            mp[num]++;
        }

        int maxFrequency = 0;
        for (auto it : mp) {
            maxFrequency = std::max(maxFrequency, it.second);
        }

        int cnt = 0;
        for (auto it : mp) {
            if (it.second == maxFrequency) {
                cnt += it.second;
            }
        } 
        return cnt;
    }
};
