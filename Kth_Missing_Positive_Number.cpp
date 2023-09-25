int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int missing_number = vec[mid] - (mid + 1);
        if(missing_number < k){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + k;
}
