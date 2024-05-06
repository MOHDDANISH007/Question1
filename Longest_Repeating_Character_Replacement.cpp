class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int length = s.size();
        int changes = 0, maxF = 0, result = 0;
        unordered_map<int, int> mp;

        while(r < length){
            mp[s[r] - 'A']++;
            maxF = max(maxF, mp[s[r]-'A']);
            // c\out << maxF << endl;

            changes = (r - l + 1) - maxF;
            while(changes > k && l < r){
                mp[s[l]-'A']--;
                maxF = 0;
                for(int i = 0; i < 26; i++){
                    maxF = max(maxF, mp[i]);
                }
                l++;
                changes = (r - l + 1) - maxF;
            }
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }
};
