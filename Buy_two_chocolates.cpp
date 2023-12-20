#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {
        int ans = money;

        sort(prices.begin(), prices.end());

        int first_smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for (auto it : prices) {
            if (it <= first_smallest) {
                second_smallest = first_smallest;
                first_smallest = it;
            } else if (it <= second_smallest) {
                second_smallest = it;
            }
        }

        if((first_smallest + second_smallest <= money) && (first_smallest != INT_MAX && second_smallest != INT_MAX)){
            return (ans - first_smallest - second_smallest);
        }

        

        return money;
    }
};
