class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxi = 0;
        int i = 0, j = 0;
        int cnt = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                cnt++;
                maxi = max(cnt,maxi);
                i++;
            }
            j++;
        }
        return maxi;
    }
};

