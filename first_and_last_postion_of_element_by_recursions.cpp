#include <iostream>
using namespace std;

int first(int arr[], int s, int e, int target) {
    if (s > e) {
        return -1;
    }
    
    int mid = s + (e - s) / 2;
    
    if (arr[mid] == target) {
        if (mid == s || arr[mid - 1] != target) {
            return mid;
        } else {
            return first(arr, s, mid - 1, target);
        }
    } else if (arr[mid] < target) {
        return first(arr, mid + 1, e, target);
    } else {
        return first(arr, s, mid - 1, target);
    }
}

int last(int arr[], int s, int e, int target) {
    if (s > e) {
        return -1;
    }
    
    int mid = s + (e - s) / 2;
    
    if (arr[mid] == target) {
        if (mid == e || arr[mid + 1] != target) {
            return mid;
        } else {
            return last(arr, mid + 1, e, target);
        }
    } else if (arr[mid] < target) {
        return last(arr, mid + 1, e, target);
    } else {
        return last(arr, s, mid - 1, target);
    }
}

int main() {
    int size = 7;
    int arr[size] = {1, 2, 3, 4, 4, 5, 6};
    int s = 0;
    int e = size - 1;
    int target = 5;
    int firstOccurrence = first(arr, s, e, target);
    int lastOccurrence = last(arr, s, e, target);
    
    cout << "First Occurrence: " << firstOccurrence << endl;
    cout << "Last Occurrence: " << lastOccurrence << endl;
    
    return 0;
}
