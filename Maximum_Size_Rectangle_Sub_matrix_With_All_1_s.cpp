#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int leftsmall[n];
    int rightsmall[n];

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            leftsmall[i] = 0;
        } else {
            leftsmall[i] = st.top() + 1;
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (st.empty()) {
            rightsmall[i] = n - 1;
        } else {
            rightsmall[i] = st.top() - 1;
        }
        st.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxi;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m) {
    int area = largestRectangleArea(mat[0]);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 0) {
                mat[i][j] = mat[i][j] + mat[i - 1][j];
            } else {
                mat[i][j] = 0;
            }
        }

        int new_area = largestRectangleArea(mat[i]);
        area = max(area, new_area);
    }
    return area;
}
