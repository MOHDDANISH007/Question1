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

// Approach 1 which is brute force time complexity is o(n^2)
class Solution {
public:
    int maxi = INT_MIN;

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    } 

    void calculateDiameter(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        int leftHeight = height(root->left); // 1-> left height is 3 and now for 1 -> right height is 1....
        int rightHeight = height(root->right);
        maxi = max(leftHeight + rightHeight, maxi);

        calculateDiameter(root->left);
        calculateDiameter(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calculateDiameter(root);
        return maxi;
    }
};
