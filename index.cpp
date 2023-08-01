#include <vector>
#include <climits>

using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> arr) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int i = 0;

    while (i < n) {
        if (max1 < arr[i]) {
            max2 = max1;
            max1 = arr[i];
        } else if (max2 < arr[i] && arr[i] != max1) {
            max2 = arr[i];
        }

        if (min1 > arr[i]) {
            min2 = min1;
            min1 = arr[i];
        } else if (min2 > arr[i] && arr[i] != min1) {
            min2 = arr[i];
        }

        i++;
    }

    vector<int> result;
    result.push_back(max2);
    result.push_back(min2);
    return result;
}

