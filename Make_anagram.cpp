#include <unordered_map>
#include <string>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return 0;
        }

        std::unordered_map<char, int> count_s;
        std::unordered_map<char, int> count_t;

        for (char it : s) {
            count_s[it]++;
        }

        for (char it : t) {
            count_t[it]++;
        }

        int result = 0; 

        for (auto &pair : count_s) {
            char key = pair.first;
            if (count_s[key] > count_t[key]) {
                result += count_s[key] - count_t[key];
            }
        }

        return result;
    }
};
