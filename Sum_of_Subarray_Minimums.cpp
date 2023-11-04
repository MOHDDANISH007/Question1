// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;
int sum(vector<int>& arr){
    int s = arr.size();
    int total_sum = 0;
    for(int i=0; i<s; i++){
        int min_value = INT_MAX;
        for(int j=i; j<s; j++){
            min_value = min(min_value, arr[j]);
            total_sum += min_value;
        }
    }
    return total_sum;
}

int main() {
  vector<int> arr = {1, 5, 3};
  int result = sum(arr);
  cout << "Sum of minimum values in the subarrays: " << result << endl;
  return 0;
}
