class Solution {
public:
    int findmaxi(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    double calaculateTotalHours(vector<int>& piles,int hourly){
        double totalh = 0;
        for(int i = 0;i<piles.size();i++){
            totalh += ceil((double)piles[i]/(double)hourly);
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, high = findmaxi(piles);
        while(low <= high){
            int mid = (low + high)/2;
            double totalH = calaculateTotalHours(piles,mid);
            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
