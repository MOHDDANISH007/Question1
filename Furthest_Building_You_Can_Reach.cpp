#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> bricksUsed;
        int i = 0;

        for (; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                bricks -= diff;
                bricksUsed.push(diff);

                if (bricks < 0) {
                    if (ladders > 0) {
                        // checking when going to next building retriver the bricks and when ladder is also negative then it's means there is no bricks and ladder go to the next buidling ..
                        bricks += bricksUsed.top();
                        bricksUsed.pop();
                        ladders--;
                    } else {
                        break;
                    }
                }
            }
        }

        return i;
