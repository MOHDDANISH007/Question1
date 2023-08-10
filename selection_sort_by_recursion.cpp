#include<iostream>
using namespace std;
void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }cout << endl;
}
void selection(int arr[] , int size){
    cout <<  size <<endl;
    print(arr,size);
    if(size == 0 || size ==1){
        return;
    }
    for(int i=0; i<size-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    selection(arr, size -1);

}
int main(){
    int size = 5;
    int arr[size] = {65,25,12,22,11};
    selection(arr,size);

   for(int i=0; i<size; i++){
        cout << arr[i] <<" ";
    }cout << endl;
    return 0;

}
