int longestSubarrayWithSumK(vector<int> a, long long k) {

    // Write your code here

    int len =0, count = 0;

    long long sum = 0;

    int i =0, j = 0;

    while(j < a.size()){

        sum = sum + a[j];

        count++;

        while(sum > k){

            sum = sum - a[i];

            count--;

            i++;

        }

        if(sum==k){

            len = max(len, count);

        }

        j++;

    }

    return len;

}

