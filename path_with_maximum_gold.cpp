#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int DFS(vector<vector<int>>& grid, int i, int j, int n, int m){
        // Base case: if out of grid boundaries or cell has no gold
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        // Store the original amount of gold at the current cell
        int original_gold = grid[i][j];
        
        // Mark the current cell as visited by setting its gold to 0
        grid[i][j] = 0;
        
        // Explore all four possible directions (up, down, left, right)
        int max_gold = 0;
        max_gold = max(max_gold, DFS(grid, i+1, j, n, m)); // down
        max_gold = max(max_gold, DFS(grid, i-1, j, n, m)); // up
        max_gold = max(max_gold, DFS(grid, i, j+1, n, m)); // right
        max_gold = max(max_gold, DFS(grid, i, j-1, n, m)); // left
        
        // Restore the original amount of gold at the current cell
        grid[i][j] = original_gold;
        
        // Return the sum of original gold at current cell and the maximum gold from its neighbors
        return original_gold + max_gold;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_gold = 0;

        // Iterate over each cell in the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // If the cell contains gold, perform DFS from this cell to find max gold collectable
                if(grid[i][j] != 0){
                    int collected_gold = DFS(grid, i, j, n, m);
                    max_gold = max(max_gold, collected_gold);
                }
            }
        }
        
        return max_gold;
    }
};
