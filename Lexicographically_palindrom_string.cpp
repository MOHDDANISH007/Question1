#include <iostream>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                char ch1 = min(s[i], s[j]);
                s[i] = ch1;
                s[j] = ch1;
            }
            i++;
            j--;
        }

        return s;
    }
};




        //Time complexity is O(N) and space complexity is O(N)..
        // int i = 0;
        // int j = s.size() - 1;
        // int cnt = 0;

        // string ans = s;

        // while (i <= j) {
