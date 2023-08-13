#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < pivot) {
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    int i = s;
    int j = e;
    
   
    while (i < pivotIndex && j > pivotIndex) {
        
        while (arr[i] < pivot) { //  Checking or finding index on left side which element greater then pivot 
            i++;
        }
      
        while (arr[j] > pivot) { // Checking or finding index on right side which element smaller then pivot 
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pivotIndex;
}

void quicksort(int arr[], int s, int e) {
    
    if (s >= e) {
        return ;
    }
    int p = partition(arr, s, e);
    quicksort(arr, s, p);
    quicksort(arr, p + 1, e);
    return ;
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1; 
    cout << "Before sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quicksort(arr, s, e);
    
    cout << "After Sorting " << endl;
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
