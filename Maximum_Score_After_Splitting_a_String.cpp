class Solution {
public:
// optimal approach..
    int maxScore(string s) {
        int ans = INT_MIN;

        int count_ones = count(s.begin(), s.end(), '1');
        int zero = 0;
        for(int i=0; i<=s.size()-2; i++){
            if(s[i] == '0'){
                zero++;
            }
            if(s[i] == '1'){
                count_ones--;
            }
            ans = max(ans, zero + count_ones);
        }
        return ans;






        // Brute force approach...
        // int ans =  INT_MIN;

        // for(int i=0; i<=s.size()-2; i++){
        //     int zero = 0;
        //     for(int j=0; j<=i; j++){
        //         if(s[j] == '0'){
        //             zero++;
        //         }
        //     }

        //     int ones = 0;

        //     for(int j=i+1; j<s.size(); j++){
        //         if(s[j] == '1'){
        //             ones++;
        //         }
        //     }

        //     ans = max(ans, ones + zero);
        // }

        // return ans;
    }
};
