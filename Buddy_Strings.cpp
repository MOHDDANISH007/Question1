#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        unordered_map<char, int> mp;

        // Count character frequencies in string s
        for (auto it : s) {
            mp[it]++;
        }

        // Check if strings are equal
        if (s == goal) {
            for (auto it : mp) {
                if (it.second > 1) {
                    return true;
                }
            }
            return false;
        }

        int swap_cnt = 0;
        vector<int> v;

        // Count the number of positions where characters differ
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                v.push_back(i);
            }
        }

        // Check if exactly two positions differ
        if (v.size() == 2) {
            // Swap the characters at differing positions
            swap(s[v[0]], s[v[1]]);
            return (s == goal);
        }

        return false;
    }
};

