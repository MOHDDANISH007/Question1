class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;

        int left = 0,right = 0;
        int length = s.size();
        int result = 0;

        while(right < length){
            mp[s[right]]++;

            while(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1){
                result += length - right;
                mp[s[left]]--;
                left++;
            }

            right++;
        }
        return result;
    }
};
