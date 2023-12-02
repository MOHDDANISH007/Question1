#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> char_frq;

        // Step 1: Counting the frequency of chars
        for (auto it : chars) {
            char_frq[it]++;
        }

        // Step 2: Counting the frequency of each word and comparing with character frequency
        int result = 0;

        for (auto word : words) {
            unordered_map<char, int> words_frq;
            bool good = true;  // Reset 'good' for each word

            for (auto it : word) {
                words_frq[it]++;

                if (words_frq[it] > char_frq[it]) {
                    good = false;
                    break;
                }
            }

            if (good) {
                result += word.size();
            }
        }

        // Step 3: Return the result
        return result;
    }
};
