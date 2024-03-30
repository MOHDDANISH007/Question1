#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int max_num = *max_element(nums.begin(), nums.end());
        long long int count = 0;
        long long int left = 0, right = 0, ans = 0;

        while (right < nums.size()) {
            if (nums[right] == max_num) {
                count++;
            }

            while (count >= k) {
                ans += nums.size() - right;

                if (nums[left] == max_num) {
                    count--;
                }
                
                left++;
            }

            right++;
        }

        return ans;
    }
};
