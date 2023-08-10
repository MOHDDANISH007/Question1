#include<iostream>
using namespace std;
int sqrt(int s, int e, int target){
    if(s > e){
        return -1;
    }
    int mid = s + (e-s)/2;
    int m = mid * mid;
    if(m == target){
        return mid;
    }
    if(m < target){
        return sqrt(mid+1, e,target);
    }
    else{
        return sqrt(s, mid-1,target);
    }
}



int main(){
    int n =100;
    int s = 0;
    int e = n;
    int target = n;
    int ans = sqrt(s ,e ,target);
    cout << ans <<" ";
}
