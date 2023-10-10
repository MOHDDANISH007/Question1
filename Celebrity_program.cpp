#include <iostream>
#include <stack>

using namespace std;

const int MAX = 5;  // Adjust the size according to your array size

bool knows(int arr[][5], int n, int a, int b) {
    return (arr[a][b] == 1);
}

int celebrity(int arr[][5], int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        s.push(i);
    }
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(arr, n, a, b)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }
    int ans = s.top();

    for (int i = 0; i < n; i++) {
        if (i != ans && (knows(arr, n, ans, i) || !knows(arr, n, i, ans))) {
            return -1;
        }
    }

    return ans;
}

int main() {
    int arr[5][5] = {
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0} 
    };
    int ans = celebrity(arr, 5);

    if (ans != -1) {
        cout << "The celebrity in the party is at index " << ans << endl;
    } else {
        cout << "No celebrity found in the party" << endl;
    }

    return 0;
}
