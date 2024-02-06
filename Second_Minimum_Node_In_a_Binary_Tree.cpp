#include <climits>  // Include this for INT_MAX

class Solution {
public:
    int solve(TreeNode* root, int val) {
        if (root == nullptr) {
            return -1;
        }

        // If the current node's value is greater than the given value, return it
        if (root->val > val) {
            return root->val;
        }

        // Recursively search in both left and right subtrees
        int left = solve(root->left, val);
        int right = solve(root->right, val);

        // If both left and right are valid / equal, return the smaller one
        if (left != -1 && right != -1) {
            return min(left, right);
        }

        // If either left or right is not valid, return the valid one
        return max(left, right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int result = solve(root, root->val);

        // If result is still -1, it means no second minimum exists
        if(result == -1){
            return -1;
        }
        else{
            return result;
