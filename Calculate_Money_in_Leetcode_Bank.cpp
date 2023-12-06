class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int day = 0;
        int mon = 1;

        for (int i = 0; i < n; ++i) {
            ans += mon + day;
            if (++day > 6) {
                day = 0;
                ++mon;// it means we are on the next week and we should start with monday increamenet....
            }
        }

        return ans;
    }
};
