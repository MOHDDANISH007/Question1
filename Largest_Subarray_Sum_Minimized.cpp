int func(vector<int> a, int mid) {
    int k = 1;
    long long partition = 0;
    int size = a.size();
    for (int i = 0; i < size; i++) {
        if (a[i] + partition <= mid) {
            partition += a[i];
        } else {
            k++;
            partition = a[i];
        }
    }
    return k;
}


int largestSubarraySumMinimized(vector<int> a, int k) {
   
   int low = *max_element(a.begin(), a.end());
   int high = accumulate(a.begin(), a.end(), 0);

   int size = a.size();
   while(low <= high){
       int mid = low + (high - low) / 2;
       int partition = func(a, mid);

       if(partition > k){
           low = mid + 1;
       } else {
           high = mid - 1;
       }
    }
    return low;
}
