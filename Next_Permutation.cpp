#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        // Find the first element (index-1) where nums[index-1] < nums[index]
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                index = i - 1;
                break;
            }
        }

        if (index != -1) {
            int swap_index = index;

            // Find the smallest element to the right of nums[index] that is greater than nums[index]
            for (int i = n - 1; i > swap_index; i--) {
                if (nums[i] > nums[index]) {
                    swap_index = i;
                    break;
                }
            }

            
            swap(nums[index], nums[swap_index]);
            cout << "the value of index " << index << endl;
        cout << "the value of swap index is " << swap_index << endl;
        }
        


        // Reverse..
        reverse(nums.begin() + index + 1, nums.end());
    }
};
