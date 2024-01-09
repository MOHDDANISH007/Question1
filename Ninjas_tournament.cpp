#include <bits/stdc++.h> 
using namespace std;

int calculateScore(vector<string> &matchResult, int n) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (matchResult[i] != "+" && matchResult[i] != "C" && matchResult[i] != "D") {
            int nums = stoi(matchResult[i]);
            st.push(nums);
        } else {
            if (matchResult[i] == "D") {
                st.push(st.top() * 2);
            } else if (matchResult[i] == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                int cur_element = st.top();
                st.pop();

                int prev_element = st.top();
                st.pop();
