#include<iostream>
using namespace std;
int first(int arr[], int s, int e, int target){
    if(s > e){
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        if(mid == s || arr[mid-1]!=target){
            return mid;
        }
        else{
            return first(arr, s, mid-1, target);
        }
    }
    if(arr[mid] < target){
        return first(arr, mid+1, e, target);
    }
    else{
        return first(arr, s, mid-1, target);
    }
}
int last(int arr[], int s, int e, int target){
    if(s > e){
        return -1;
    }
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        if(mid == s || arr[mid+1]!=target){
            return mid;
        }
        else{
            return first(arr, mid+1, e, target);
        }
    }
    if(arr[mid] < target){
        return first(arr, mid+1, e, target);
    }
    else{
        return first(arr, s, mid-1, target);
    }
}



int main(){
    int size = 7;
    int arr[size] = {1,1,1,2,2,3,3};
    int s = 0;
    int e = size-1;
    int target = 2;

    int ans1 = first(arr, s, e, target);
    cout  <<ans1 <<endl;
    int ans2 = last(arr, s, e, target);
    cout  <<ans2 <<endl;
    int final_answer = (ans2 - ans1) +1;
    cout << final_answer <<endl;
}
