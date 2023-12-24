#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
    int maximizeSquareArea(int m, int n, std::vector<int>& hFences,std::vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        sort(hFences.begin(), hFences.end());

        vFences.push_back(1);
        vFences.push_back(n);

        sort(vFences.begin(), vFences.end());

        std::set<long long> h_distance;

        for (int i = 0; i < hFences.size(); i++) { // finding horizontal distance..
            for (int j = i + 1; j < hFences.size(); j++) {
                h_distance.insert(hFences[j] - hFences[i]);
            }
        }

        std::set<long long> v_distance;
        long long ans = -1;

        for (int i = 0; i < vFences.size(); i++) { // checking horizontal distane is in vertical distacne or not..
            for (int j = i + 1; j < vFences.size(); j++) {
                long long ds = vFences[j] - vFences[i];
                if (h_distance.find(ds) != h_distance.end()) { // if side it is possible to form square...
                    long long area = ds * ds;
                    ans = max(ans, area);
                }
            }
        }

        int mod = 1e9 + 7;
        if (ans != -1) {
            return ans % mod;
        }
        return ans;
    }
};
