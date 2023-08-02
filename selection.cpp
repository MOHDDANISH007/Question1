#include<iostream>
#define size 5
using namespace std;
// declaration of macros.


int main(){
    int arr[size];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[min] > arr[j]){
                swap(arr[min],arr[j]);
            }
        }
    }
    for(int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }cout <<endl;

}
