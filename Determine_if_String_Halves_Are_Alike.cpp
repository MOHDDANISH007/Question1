#include <iostream>
#include <string>

class Solution {
public:
    int countVowels(const std::string& s, int start, int end) {
        int cnt = 0;
        for (int i = start; i < end; ++i) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
                cnt++;
            }
        }
        return cnt;
    }

    bool halvesAreAlike(const std::string& s) {
        int size = s.size();
        int mid = size / 2;

        int count_1 = countVowels(s, 0, mid);
        int count_2 = countVowels(s, mid, size);

        return count_1 == count_2;
    }
};


