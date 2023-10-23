class Solution {
public:
    vector<int> countBits(int n) {
    vector <int> count(n+1, 0);

    // step = 1 using loop to count the set bit with the help of i..
    for(int i=1; i<=n; i++){
        // step 2 = To count the number of 1s in i, we can use the result of i/2 / i>>1
        count[i] = count[i >> 1] + (i & 1);
    }
    // step 2 = return the answer..
    return count;
    }
};





