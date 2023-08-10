#include<iostream>
using namespace std;
void print(int arr[] , int size){

    for(int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }cout << endl;
}
void sorted(int arr[], int size){
    print(arr, size);
    cout << size << endl;
    if(size == 0 || size == 1){
        return;
    }

    for(int i=0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }

    return sorted(arr, size-1);
}
int main(){
    int size = 5;
    int arr[size] = {2,5,1,6,9};

    sorted(arr, size);

    cout <<endl;
    for(int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }cout << endl; 
}
