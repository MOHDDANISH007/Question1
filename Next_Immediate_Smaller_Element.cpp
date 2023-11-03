#include <bits/stdc++.h>
using namespace std;

void immediateSmaller(vector<int>& a) {
    int n = a.size();
    stack<int> st;
    vector<int> nse(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        if(!st.empty() && a[i] > st.top()){
            int temp = a[i];
            a[i] = st.top();
            st.push(temp);
        }
        else{
            st.push(a[i]);
            a[i] = -1;
        }
    }
}

int main() {
    vector<int> arr {10,9,8,7,6,5,4,3,2,1};
    immediateSmaller(arr);
    
    cout << "The Next Immediate Smaller Element is " << endl;
    for (auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
