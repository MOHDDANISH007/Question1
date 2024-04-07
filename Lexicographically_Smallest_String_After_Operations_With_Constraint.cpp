class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";
        int n  = s.size();
        for(int i=0; i<n; i++){
            int moving_back_side = s[i] - 'a' , moving_front_side = 'z' - s[i] + 1;
            int minCostToReachA = min(moving_back_side, moving_front_side);
            if(k >= minCostToReachA){
                k -= minCostToReachA;
                ans += 'a';
            }
            else{
                char ch = s[i] - k;
                ans += ch;
                k = 0;
            }
        }
        return ans;
    }
};
