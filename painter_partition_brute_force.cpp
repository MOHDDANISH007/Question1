#include<iostream>
#include<vector>
using namespace std;

int maxi(vector<int>& arr, int n) {
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > ans) {
            ans = arr[i];
        }
    }
    return ans;
}
int fun(vector<int> arr, int k, int board_paint){
    int painter = 1;
    int board = 0;

    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] + board <= board_paint){
            board += arr[i];
        }
        else{
            painter ++;
            board = arr[i];
        }
    }
    return painter;
}
int painter_partition(vector<int> arr, int k){
    // write code.
    int size = arr.size();

    int maxElement = maxi(arr, size);
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    for(int i=maxElement; i<sum; i++){
        int cnt_painter = fun(arr,k, i);
        if(cnt_painter == k){
            return i;
        }
    }
    return maxElement;
}

int main(){
    vector <int> arr = {10, 20 , 30 ,40};
    int noOfPainter = 2;

    int ans = painter_partition(arr, noOfPainter);

    cout << ans << endl;
    return 0;

}
