#include <bits/stdc++.h>
using namespace std;

void subset(int arr[], vector<int> &dc, int i, int n){
    if(i == n){
        for(auto x : dc){
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element
    dc.push_back(arr[i]);
    subset(arr, dc, i + 1, n);

    // Exclude the current element
    dc.pop_back();
    subset(arr, dc, i + 1, n);
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Element are insert in the array" << endl;
    vector<int> dc;
    int i = 0;
    subset(arr, dc, i, n);

    return 0;
}
