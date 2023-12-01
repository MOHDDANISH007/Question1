// 1 -> Brute force approach


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n!=0){
            if(n%2 != 0){
                cnt++;
            }
            n>>=1;
        }
        return cnt;

    }
};



// optimal approach


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n!=0){
            n = n&(n-1); cnt++;
        }
        return cnt;

    }
};
