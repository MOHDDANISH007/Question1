#include <bits/stdc++.h>
using namespace std;  // Add the namespace

int floorSearch(vector<int> &arr, int X, int N) {
    int ans = -1;
    int s = 0;
    int e = N - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= X) {
            ans = arr[mid];
            s = mid + 1;   // Modify this line to search in the left half
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

