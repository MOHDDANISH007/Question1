// 1st optimal approach


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time_mini = 0;
        for(int i=0; i<points.size()-1; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i+1][0];
            int y2 = points[i+1][1];

            int dx = abs(x1-x2);
            int dy = abs(y1-y2);

            time_mini += min(dx, dy) + abs(dx-dy);

        }
        return time_mini;

    }
};



// 2nd optimal approach

#include <bits/stdc++.h>
 
class Solution {
public:
    int solve(vector<int> p1, vector<int> p2){
        return max(abs(p1[0]- p2[0]),abs(p1[1]-p2[1]));
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int mini_time = 0;

        for(int i=0; i<points.size()-1; i++){
            mini_time += solve(points[i], points[i+1]);

        }
        return mini_time;
    }
};
