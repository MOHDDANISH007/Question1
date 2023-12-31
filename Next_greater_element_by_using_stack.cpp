#include <bits/stdc++.h>


vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	 vector<int> nge(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }

            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(arr[i]);
        }
        
	return nge;
}
