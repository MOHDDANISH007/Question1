class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi_profit = 0;
        int n = prices.size();
        int mini = prices[0];
        for(int i=0; i<n; i++){
            if(prices[i] < mini){
                mini = prices[i];
            }
            else{
                int current_profit = prices[i] - mini;
                maxi_profit = max(maxi_profit, current_profit);
            }
        }
        return maxi_profit;
    }
};
