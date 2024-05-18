/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function for DFS traversal
    int dfs(TreeNode* root, int& moves) {
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively compute the excess coins in the left and right subtrees
        int leftExcess = dfs(root->left, moves);
        int rightExcess = dfs(root->right, moves);
        
        // Total excess coins for this node
        int excess = root->val + leftExcess + rightExcess - 1;
        
        // The number of moves needed is increased by the absolute value of the excess
        moves += abs(excess);
        
        // Return the excess to the parent node
        return excess;
    }
    
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};
