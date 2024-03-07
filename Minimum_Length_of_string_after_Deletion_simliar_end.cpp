class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0 ;
        int right = n -1;

        while(left<right && s[left] == s[right]){
            // char ch = s[left];
            char prefix = s[left];
            char suffix = s[right];

            // Now checking how much prefix is possible.
            while(left<right && s[left] == prefix){
                left++;
            }

            // Now checking how much suffix is possible

            while(right>=left && s[right] == suffix){
                right--;
            }
        }

        return right - left + 1;
    }
};
