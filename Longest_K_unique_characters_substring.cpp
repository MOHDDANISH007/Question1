class Solution{
      public:
        int longestKSubstr(string s, int k) {
            int i=0, j=0, ans=-1;
            unordered_map<char, int> mp;
            
            while(j<s.size()) {
                mp[s[j]]++;
                
                // Shrink the window if we exceed k distinct characters
                while(mp.size() > k) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                // Calculate the current window size
                if(mp.size() == k) ans = max(ans, j-i+1);
                j++;
            }
            return ans;
        }
    };
