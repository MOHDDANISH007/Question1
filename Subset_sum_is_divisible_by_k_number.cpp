#include <bits/stdc++.h>
using namespace std;

void subset(int arr[], vector<int> &dc, int sum, int n, int i, int k) {
    // step 1 = checking I am in range or not ..
    if (n == i) {
        if (sum % k == 0) {
            for (auto it : dc) {
                cout << it << " ";
            }
            cout << endl;
        }
        return; // Added return statement to stop processing after finding a valid subset.
    }
    // step 2 = Include The element..
    dc.push_back(arr[i]);
    sum += arr[i];
    subset(arr, dc, sum, n, i + 1, k);

    // step 3 = Exclude The element..
    sum -= arr[i];
    dc.pop_back();
    subset(arr, dc, sum, n, i + 1, k);
}

int main() {
    int n;
    cout << "The size of the array is: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dc;
    int i = 0;
    int k;
    cout << "Insert the number which is divisible by k: ";
    cin >> k;
    int sum = 0;
    subset(arr, dc, sum, n, i, k);

    return 0;
}
