#include <bits/stdc++.h>
#include <vector>

using namespace std;

int maximum_pair(vector<int> arr, int min_diff) {
    sort(arr.begin(), arr.end());

    vector<int> indices;
    std::size_t i = 0;
    std::size_t size = arr.size();

    for (std::size_t j = 0; j < size; ++j) {
        while (i < size && arr[i] - arr[j] < min_diff) {
            ++i;
        }

        if (i >= size) {
            break;
        }
        if (arr[i] - arr[j] != 0) {
            indices.push_back(i);
        }
    }

    int count_pair = 0;
    for (std::size_t i = 0; i < indices.size(); ++i) {
        count_pair++;
    }

    return count_pair;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    int min_diff = 3;
    int ans = maximum_pair(arr, min_diff);

    cout << "The maximum pair will be is " << ans << endl;

    return 0;
}
