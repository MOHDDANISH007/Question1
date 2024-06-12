class Solution {
public:
    unordered_map<char, string> mp{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    void dfs(string digits, vector<string>& ans, string temp, int i){
        if (i >= digits.length()) {
            ans.push_back(temp);
            return;
        }
        string t = mp[digits[i]];
        for (int j = 0; j < t.length(); j++) {
            dfs(digits, ans,  temp + t[j], i + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string temp = "";
        dfs(digits, ans, temp, 0);
        return ans; 
    }
};
