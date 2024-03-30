#include <vector> 
#include <algorithm> // Include algorithm for sort

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) { 
        // int candidate = 1;
        // std::sort(nums.begin(), nums.end()); // Use std::sort instead of sort

        // int length = nums.size();

        // for(int i = 0; i < length; i++){ // Fix the loop condition to iterate over the valid indices of nums
        //     if(nums[i] == candidate){
        //         candidate++;
        //     }
        //     else if(candidate < nums[i]){
        //         return candidate;
        //     }
        // }   
        // return candidate;



        // This approach is know as Pigeonhole principal

        int length = nums.size();

        // Step 1: Replace non-positive integers or integers greater than the array size
        // with a placeholder value (length + 1).
        for(int i = 0; i < length; ++i) {
            if(nums[i] <= 0 || nums[i] > length) {
                nums[i] = length + 1;
            }
        }

        // Step 2: Treat the array as a hash table. Mark the corresponding "seat" (index)
        // by negating the value.
        for(int i = 0; i < length; ++i) {
            int element = abs(nums[i]); // Using abs() to handle negative values
            if(element <= length) {
                nums[element - 1] = -abs(nums[element - 1]); // Mark the seat
            }
        }

        // Step 3: Find the first positive integer (missing integer).
        for(int i = 0; i < length; ++i) {
            if(nums[i] > 0) {
                return i + 1; // The first missing positive integer
            }
        }

        // If no positive integer is found, return length + 1.
        return length + 1;
    }
};
