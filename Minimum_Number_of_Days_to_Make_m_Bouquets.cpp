class Solution {
public:
    int mini_element(vector<int>& bloomDay){
        int mini = INT_MAX;
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
            mini = min(bloomDay[i], mini);
        }
        return mini;
    }

    int maxi_element(vector<int>& bloomDay){
        int maxi = INT_MIN; // Change INT_MAX to INT_MIN
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
            maxi = max(bloomDay[i], maxi);
        }
        return maxi;
    }

    bool ispossible(vector<int>& bloomDay, int days, int m, int k){
        int count = 0, total_no_bouquets = 0;

        int n = bloomDay.size();
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= days){
                count++;
                if(count == k){
                    // checking how many many bouquets are prepared in that day
                    total_no_bouquets++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        if(total_no_bouquets >= m){
            return true;
        }
        else{
            return false;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // step 1 = finding minimum and maximum element in the array

        long long low = mini_element(bloomDay); // Change to long long
        long long high = maxi_element(bloomDay); // Change to long long

        long long ans = -1 ; // Change to long long
        // step 2 = finding on which day my flower is in bloom

        while(low <= high){
            long long mid = (high + low) / 2;

            if(ispossible(bloomDay, mid, m, k) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << ans << endl;
        return ans;
    }
};
