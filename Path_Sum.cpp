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
    bool solve(TreeNode* root, int targetSum){

          // Base case: if the current node is null, return false
        if (root == nullptr) {
            return false;
        }

        // If the current node is a leaf and its value is equal to the remaining targetSum
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            return true;
        }

        // Recursively check for the remaining targetSum in the left and right subtrees
        bool leftPath = solve(root->left, targetSum - root->val);
        bool rightPath = solve(root->right, targetSum - root->val);

        // Return true if either the left or right subtrees has a path with the remaining targetSum
        return leftPath || rightPath;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};
