#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int n = stalls.size();
    int e = stalls[n - 1];
    int ans = -1;
    int mid;

    while (s <= e) {
        mid = s + (e - s) / 2;
        if (isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

