class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        string ans = "";

        for(int i=1; i<=num.size()-1; i++){

            if(num[i] == num[i-1] && num[i] == num[i+1]){
                ans += num[i];
                ans += num[i-1];
                ans += num[i+1];

                result = max(ans,result);
                ans = "";
            }
        }
        return result;
    }
};
