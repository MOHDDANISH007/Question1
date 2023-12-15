class Solution {
public:
    int solve(int n, int& count){
        if(n == 0){
            return count;
        }
        if(n % 2 == 0){
            count++;
            return solve(n/2, count);
        }
        else{
            count++;
            return solve(n-1, count);
        }
    }
    int numberOfSteps(int num) {
        int count = 0;
        solve(num , count);
        return count;
    }
};
