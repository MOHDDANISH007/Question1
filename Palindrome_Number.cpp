class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int y = x;
        long long reverse = 0;
        while(x!=0){
            int digit = x % 10;
            reverse = (reverse * 10) + digit;
            x = x/10;
        }
        if(reverse == y){
            return true;
        }
        else{
            return false;
        }    
    }
};
