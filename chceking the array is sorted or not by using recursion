#include<iostream>
using namespace std;

bool sorted(int arr[], int size){
    if(size ==0 || size ==1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remain_part = sorted(arr+1, size-1);
        return remain_part;
    }
}



int main(){
    int size = 5;
    int arr[size] ={1,2,1,4,5};
    bool ans = sorted(arr, size);
    if(ans){
        cout <<"Is sorted" <<endl;
    }
    else{
        cout << "Not sorted" <<endl;
    }
}
