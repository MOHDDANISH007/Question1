#include <vector>
#include <iostream>
using namespace std;

vector<int> countGreater(vector<int>& arr, vector<int>& query) {
    vector<int> v;

    for (int i = 0; i < query.size(); i++) {
        int cnt = 0;
        for (int j = query[i] + 1; j < arr.size(); j++) {
            if (arr[j] > arr[query[i]]) {
                cnt++;
            }
        }
        v.push_back(cnt);
    }

    return v;
}

