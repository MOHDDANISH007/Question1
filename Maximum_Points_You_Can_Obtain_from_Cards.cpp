class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;

        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;

        for(int i=0; i<k; i++){
            lsum += cardPoints[i];
        }

        maxSum = lsum; // Initialize maxSum with the sum of first k elements

        for(int i=k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[n-1];
            maxSum = max(maxSum, lsum + rsum);
            n--;
        }

        return maxSum;
  
  }
};
