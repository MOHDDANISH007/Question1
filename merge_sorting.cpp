// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
void merge(int arr[] ,int low ,int mid ,int high){
   vector <int> temp;
    int left = low;
    int right = mid +1;
    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
           temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= high){
        temp.push_back(arr[right++]);
    }
    for(int i=low; i<=high ;i++){
        arr[i] = temp[i-low];
    }
}


void mergesort(int arr[], int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;
    mergesort(arr,low, mid);  //left half
    mergesort(arr, mid+1, high); // right half
    merge(arr, low, mid, high);
    return;
}


int main() {
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "befor sorting" <<endl;

    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }cout <<endl;

    mergesort(arr,0 ,n-1);

    cout << "after sorting" <<endl;
    
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }cout <<endl;
    return 0;
}
