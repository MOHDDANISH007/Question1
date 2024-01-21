#include <vector>
using namespace std;

class Solution {
public:
    int set_bit(int n) {
        int cnt = 0;
        for (int i = 31; i >= 0; i--) {
            if ((n >> i) & 1) {
                cnt++;
            }
        }
        return cnt;
    }

    bool check(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        vector<int> count_set_bit(nums.size());

        // Count set bits for each element
        for (int i = 0; i < nums.size(); i++) {
            count_set_bit[i] = set_bit(nums[i]);
        }

        // Try sorting the elements using bubble sort.
        int k = 0;
        while (k < nums.size()) {
            for (int i = 1; i < nums.size(); i++) {
                if (count_set_bit[i - 1] == count_set_bit[i] && nums[i - 1] > nums[i]) {
                    // Swap the elements and update count_set_bit.
                    swap(nums[i], nums[i - 1]);
                    swap(count_set_bit[i], count_set_bit[i - 1]);
                }
            }

            if (check(nums)) {
                return true;
            }
            k++;
        }
        return false;
    }
};
