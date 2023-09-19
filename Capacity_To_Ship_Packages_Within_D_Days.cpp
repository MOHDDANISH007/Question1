class Solution {
public:
    
    int find_day(vector<int>& weights, int capacity){
        int days = 1;
        int load = 0;
        int n = weights.size();
        for(int i=0; i<n; i++){
            if(load + weights[i] > capacity){
                days++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    // finding the max element in the weights.
    int max_element(vector<int>& weights){
        int n = weights.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            ans = max(weights[i], ans);
        }
        return ans;
    }
    // finding the sum in the weights.
    int sum_element(vector<int>& weights){
        int n = weights.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += weights[i]; 
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        //step 1 = find the maximum element in the array of weights 
        int low = max_element(weights);

        // step 2 = find the sum of all the element in the array of weights
        // because the range will be [max_element sum of array element].

        int high = sum_element(weights);

        while(low <= high){
            // step 3 = finding the middle element in the array

            int mid = low + (high - low) / 2;
            //step 4 = checking the capacity of the ship whether it will transfer all 
            // the product or not in the given days

            int no_of_days = find_day(weights, mid);
            if(no_of_days <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        } 
        // step 5 = Return your answer.
        return ans;
    }
};
