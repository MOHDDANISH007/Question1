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

        int leftHeight = height(root->left);
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
