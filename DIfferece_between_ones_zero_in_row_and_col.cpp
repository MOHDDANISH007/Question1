#include <vector>
using namespace std;


class Solution {
public:

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vector<int> row_one(grid.size(), 0);
    vector<int> col_one(grid[0].size(), 0);

    // Count ones in each row
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                row_one[i]++;
                
            }
        }
    }

    // Count ones in each column
    for (int i = 0; i < grid[0].size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            if (grid[j][i] == 1) {
                col_one[i]++;
            }
        }
    }

    vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            // Fix the formula for calculating the result
            ans[i][j] = (row_one[i] + col_one[j]) - ((grid.size() - row_one[i]) + (grid[0].size() - col_one[j]));
        }
    }
    return ans;
    }
};




// Brute force approach


// Brute force approach
// don't use my solution it is brute force and When u submit this code
//  it give u TLE.
// Because when u see constraint it  1 <= m * n <= 10^5
// this TC is o(m*n) + o(m+n)



// #include <vector>

// using namespace std;

// class Solution {
// public:

//     int value(vector<vector<int>>& grid, int row, int col) {
//         int one_row = 0;
//         int one_col = 0;

//         for (int i = 0; i < grid[0].size(); i++) {
//             if (grid[row][i] == 1) {
//                 one_row++;
//             }   
//         }

//         for (int i = 0; i < grid.size(); i++) {
//             if (grid[i][col] == 1) {
//                 one_col++;
//             }
//         }

//         return (one_row + one_col) - ((grid.size() - one_row) + (grid[0].size() - one_col));
//     }

//     vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
//         vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));

//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 diff[i][j] = value(grid, i, j);
//             }
//         }
//         return diff;
//     }
