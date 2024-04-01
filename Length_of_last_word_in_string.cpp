
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int ans = 0;
        reverse(s.begin(), s.end());

        // Assuming there is a space after reversing to handle trailing spaces.
        bool foundNonSpace = false;

        for (char it : s) {
            if (it != ' ' && foundNonSpace == false) {
                foundNonSpace = true;
            }
            if (foundNonSpace == true && it != ' ') {
                ans++;
            } else if (foundNonSpace == true && it == ' ') {
                break;
            }
        }
        return ans;
    }
};
