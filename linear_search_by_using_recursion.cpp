#include<iostream>
using namespace std;

bool linear_search(int *arr, int size, int key){
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        bool remain_part = linear_search(arr+1, size-1, key);
        return remain_part;
    }
}



int main(){
    int size = 5;

    int arr[size] = {1,2,3,4,5};
    int key = 6;
    bool ans = linear_search(arr, size, key);
    if(ans){
        cout << " Present " <<endl;
    }
    else{
        cout << " Absent " <<endl;
    }
}
