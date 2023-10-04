#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool found = false;  // Flag to check if a smaller element is found
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                ans.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            ans.push_back(-1);  // If no smaller element is found, push -1
        }
    }
    return ans;
}

