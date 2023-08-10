#include<iostream>
using namespace std;

int findPeakIndex(int arr[], int s, int e) {
    if (s == e) {
        return s;
    }
    int mid = s + (e - s) / 2;
    
    if (arr[mid] < arr[mid + 1]) {
        return findPeakIndex(arr, mid + 1, e);
    } else {
        return findPeakIndex(arr, s, mid);
    }
}

int main() {
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    int s = 0;
    int e = size - 1; // Corrected the end index
    int peakIndex = findPeakIndex(arr, s, e);
    if (peakIndex != -1) {
        cout << "Peak element index is: " << peakIndex << endl;
        cout << "Peak element value is: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak element found." << endl;
    }
    
    return 0;
}
