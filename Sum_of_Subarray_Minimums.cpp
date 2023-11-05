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










// It is  optimal solution


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int size){
        vector<int> NSL(size);
        stack<int> st;

        for(int i = 0; i < size; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                NSL[i] = st.top();
            }
            else{
                NSL[i] = -1; // If no smaller element on the left, assign -1
            }
            st.push(i);
        }
        return NSL;
    }

    vector<int> getNSR(vector<int>& arr, int size){
        vector<int> NSR(size);
        stack<int> st;

        for(int i = size - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                NSR[i] = st.top();
            }
            else{
                NSR[i] = size; // If no smaller element on the right, assign 'size'
            }
            st.push(i);
        }
        return NSR;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        // Step 1: Determine the size of the input array
        int size = arr.size();

        // Step 2: Find the Next Smaller Element (NSL) on the left for each element
        vector<int> NSL = getNSL(arr, size);

        // Step 3: Find the Next Smaller Element (NSR) on the right for each element
        vector<int> NSR = getNSR(arr, size);

        long long sum = 0;
        int M = 1e9 + 7; // Modulo value to handle large results and keep the answer within a defined range

        for(int i = 0; i < size; i++){
            // Calculate the distance to the nearest smaller element on the left (NSL) and right (NSR)
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            // Calculate the subarray count using the distances on both sides
            long long subarray = ls * rs;

            // Calculate the sum considering the current element and its associated subarray count
            long long total_sum = arr[i] * subarray; 

            // Update the total sum while considering the modulo operation
            sum = (sum + total_sum) % M; 
        }
        return sum;
    }
};





