class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        int max_diagonal = 0;

        for(auto it: dimensions) {
            int t = it[0] * it[0] + it[1] * it[1];

            if(t > max_diagonal || (t == max_diagonal && it[0] * it[1] > area)) {
                max_diagonal = t;
                area = it[0] * it[1];
            }
        }
        return area;
    }
};
