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
    void solve(TreeNode* root, int value, int& sum) {
        if (root->left == nullptr && root->right == nullptr) {
            value = (value * 10) + root->val;
            sum += value;
            return;
        }

        value = (value * 10) + root->val;

        if (root->left != nullptr) {
            solve(root->left, value, sum);
        }
        if (root->right != nullptr) {
            solve(root->right, value, sum);
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int value = 0;
        int sum = 0;
        solve(root, value, sum);
        return sum;
    }
};
