#include <iostream>
#include <map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> m1;
        map<char, int> m2;

        // Count occurrences in the first string
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
        }

        // Count occurrences in the second string
        for (int i = 0; i < t.size(); i++) {
            m2[t[i]]++;
        }

        // Compare the occurrences in both maps
        for (auto it : m1) {
            if (m2.find(it.first) == m2.end() || m2[it.first] != it.second) {
                return false;
            }
        }

        return true;
    }
};



