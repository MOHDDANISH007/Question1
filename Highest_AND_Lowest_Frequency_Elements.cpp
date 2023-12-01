#include <vector>
#include <map>
#include <climits>

using namespace std;  // Adding the 'using namespace std' directive

vector<int> getFrequencies(vector<int>& v) {
    map<int, int> mp;

    for (int i = 0; i < v.size(); i++) {
        mp[v[i]]++;
    }

    int max_fre_element = INT_MIN;
    int min_fre_element = INT_MAX;

    int max_fre = INT_MIN;
    int min_fre = INT_MAX;

    for (auto it : mp) {
        if (max_fre < it.second) {
            max_fre = it.second;
            max_fre_element = it.first;
        }

        if (min_fre > it.second) {
            min_fre = it.second;
            min_fre_element = it.first;
        }
    }
    return {max_fre_element, min_fre_element};
}




