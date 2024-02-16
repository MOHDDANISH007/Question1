#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;

        // Building Frequency Map
        for (auto &it : arr) {
            mp[it]++;
        }

        // Building Frequency Vector
        vector<int> freq;
        for (auto &it : mp) {
            freq.push_back(it.second);
        }

        // Sorting the Frequency Vector
        sort(freq.begin(), freq.end());

        // Calculating Minimum Unique Integers
        for (auto it : freq) {
            if (k >= it) {
                cnt++;
                k -= it;
            } else {
                break;
            }
        }

        // Returning the Result
        return freq.size() - cnt;
    }
};


