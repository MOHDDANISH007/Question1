int binary(vector<int>& arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;  // Return -1 if the target is not found.
}

int findpivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n - 1;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[e]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s;
}

int search(vector<int>& arr, int n, int k) {
    int pivot = findpivot(arr, n);
     
    // searching in right part of the pivot
    if (arr[pivot] <= k && k <= arr[n - 1]) {
        return binary(arr, pivot, n - 1, k);
    } else { // searching in left part of the pivot

        return binary(arr, 0, pivot - 1, k);
    }
}

