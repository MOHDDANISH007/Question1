int missingNumber(vector<int>&a, int N) {
    // Write your code here.
    int sum = (N * (N+1))/2;
    int temp = 0;

    for(int i=0; i<N-1; i++) 
    temp += a[i];

    return sum-temp;
}

