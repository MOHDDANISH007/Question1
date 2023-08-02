int linearSearch(int n, int num, vector<int> &arr) {
    int store = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == num){
            store = i;
            return store;
        }
    }
    return store;
}

