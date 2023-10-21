class Solution {
public:
    int hammingDistance(int x, int y) {
        int i = 0;
        int ans = 0;
        while(x || y){
            int bit_1 = x % 2;
            int bit_2 = y % 2;
            if(bit_1 != bit_2){
                ans++;
            }
            x = x >> 1; // Right-shift x by 1 to check the next bit
            y = y >> 1;  // Right-shift y by 1 to check the next bit
        }
        return ans;
    }

};
