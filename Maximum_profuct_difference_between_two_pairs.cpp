class Solution {
public:
   int maxProductDifference(std::vector<int>& nums) {
    if (nums.size() < 4) {
        // Handle the case when there are not enough elements in the array.
        // You might want to return an appropriate value or handle it according to the requirements.
        return 0;
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for (auto it : nums) {
        if (it > largest) {
            second_largest = largest;
            largest = it;
        } else if (it > second_largest) {
            second_largest = it;
        }
    }

    for (auto it : nums) {
        if (it < smallest) {
            second_smallest = smallest;
            smallest = it;
        } else if (it < second_smallest) {
            second_smallest = it;
        }
    }

    return ((largest * second_largest) - (second_smallest * smallest));
}
};


// In this appraoch not might check that enough element condition..

// Handle the case when there are not enough elements in the array.
// You might want to return an appropriate value or handle it according to the requirements

//  int maxProductDifference(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         map<int, int> mp;
//         for (int i = 1; i < nums.size(); i++) {
//             int mul = nums[i] * nums[i - 1]; 
//             mp[mul]++;
//         }
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         for (auto it : mp) {
//             mini = min(mini, it.first); // Access the key, not the entire pair
//             maxi = max(maxi, it.first);
//         }
//         return maxi - mini;
//     }
