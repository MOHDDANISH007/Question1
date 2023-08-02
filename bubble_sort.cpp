#include<iostream>
#define size 5
using namespace std;
int main(){
    int arr[size];

    // taking input .
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    // Algorithm for sorting.
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j] < arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        }   
    }
    // printing portion
    for(int i=0; i<size; i++){
        cout << arr[i] <<" "; 
    }
}
