// In this approach 
// Time complexity = O(n)
//Space complexity = O(1)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size() / 4; // Determine the expected size of a contiguous segment representing 25% of the array
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == arr[i + size]) { // Check if the current element is equal to the element within the next 25% range in the array
                return arr[i]; // Return the special integer if found
            }
        }
        
        return -1; // Return -1 if no special integer is found
    }
};


//Time complexity = O(n)
//Space complexity = O(n)

#include <vector>
#include <map>
#include <climits>

class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        std::map<int, int> mp;

        for (auto it : arr) {
            mp[it]++;
        }

        int ans = INT_MIN;
        int result = 0;

        for (auto it : mp) {
            if (it.second > ans) {
                ans = it.second;
                result = it.first;
            }
        }

        return result;
    }
};
