#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrefixAndSuffix(const string& str1, const string& str2) {
    if (str1.length() > str2.length())
        return false;

    for (int i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i])
            return false;
    }

    int p = str2.length() - 1;

    for (int i = str1.length() - 1; i >= 0; --i) {
        if (str1[i] != str2[p])
            return false;
        --p;
    }

    return true;
}

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        string word1, word2;

        for (int i = 0; i < words.size(); ++i) {
            word1 = words[i];
            for (int j = i + 1; j < words.size(); ++j) {
                word2 = words[j];
                if (isPrefixAndSuffix(word1, word2))
                    ++count;
            }
        }

        return count;
    }
};
