#include <iostream>
#include <vector>

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
int fun(vector<int> arr, int lowpages){
    // write code...
    int cnt_student = 1;
    int cnt_pages = 0;
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(arr[i] + cnt_pages <= lowpages){
            cnt_pages += arr[i];
        }
        else{
            cnt_student ++;
            cnt_pages = arr[i];
        }
    }
    return cnt_student;
}
int bookallocation(vector<int> arr, int size, int m){
    // write the code

    int maxElement = maxi(arr, size);
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    for(int i = maxElement; i<sum; i++){
        int cnt_student = fun(arr, i);
        if(m == cnt_student){
            return i;
        }
    }
    return -1;
}





int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = arr.size();


    int noOfStudent  = 4;
    int ans = bookallocation(arr , n, noOfStudent);

    cout << "Answer is = " << ans << endl;
    return 0;
}
