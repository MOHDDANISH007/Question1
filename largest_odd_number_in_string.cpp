class Solution {
public:
    string largestOddNumber(string num) {
        int size = num.size()-1;

        string ans = ""; /// storeing the string larger number..

        bool flag = false; // This use for when we visit any particular number is even or false and set false or true for to store that number or not..
        
        for(int i=size; i>=0; i--){
            if( (num[i] - '0') % 2 != 0){
                flag = true;
            }
            if(flag == true){
                ans += num[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
