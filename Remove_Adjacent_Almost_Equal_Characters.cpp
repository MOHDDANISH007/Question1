class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i += 1) {
            if(abs(s[i] - s[i + 1]) <= 1) {
                ans += 1;
                i += 1;
            }
        }
        return ans;
    }
};
