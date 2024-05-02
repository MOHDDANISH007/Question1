#include <string>
#include <algorithm> // For std::reverse

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int j = 0;
        int length = word.size();

        while (j < length) {
            if (word[j] == ch) {
                reverse(word.begin() + i, word.begin() + j + 1); // Fix the range for reverse
                return word; // Add the missing semicolon
            }
            j++;
        }
        
        return word; // Add the missing semicolon
    }
};
