#include <iostream>
#include <string>

class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {

        int max_length = -1;
        int n = s.size();
        map<char, int> mp;

        for (int i = 0; i < n; i++) {
            auto it = mp.find(s[i]);
            if (mp.find(s[i]) != mp.end()) {
                max_length = std::max(max_length, i - it->second - 1);
            } else {
                mp[s[i]] = i;
            }
        }

        return max_length;




























        // int max_length = -1;  // Initialize to -1 for the case when no equal characters are found
        // int cnt = 0;

        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = i + 1; j < s.size(); j++) {
        //         if (s[i] != s[j]) {
        //             cnt++;
        //         } else {
        //             max_length = std::max(max_length, j - i - 1);
        //             cnt = 0;
        //         }
        //     }
        // }

        // return max_length;
    }
};



