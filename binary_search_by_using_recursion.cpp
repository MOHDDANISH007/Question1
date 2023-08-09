#include<iostream>
using namespace std;
int binary_search(int arr[] ,int s,int e, int key){
    if(s > e){
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[mid] < key){
        return binary_search(arr, mid+1, e, key);
    }
    else{
        return binary_search(arr, s, mid-1, key);
    }
}



int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,6};
    int s = 0;
    int e = size-1;  
    int key = 5;  
    int ans = binary_search(arr, s, e,key);
    cout << "Answer is " << ans <<endl;
    return 0;
}
