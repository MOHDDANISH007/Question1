class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;

        int n = s.size();

        int start = 0;
        int end = 0;
        int curLength = 0;
        int maxLength = 0;

        while(end < n){
            // if element is present in the map then..
            if(mp.find(s[end]) != mp.end()){
                // then I want to shrink my array size but if s[r] > start then only
                if(mp[s[end]] >= start){
                    start = mp[s[end]] + 1;
                }
            }
            curLength = end - start + 1;
            maxLength = max(maxLength , curLength);

            mp[s[end]] = end;

            // Expand the array..
            end++;
        }
        return maxLength;
    }
};
