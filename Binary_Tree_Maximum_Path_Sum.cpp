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
    int sum_path(TreeNode* root, int& maxi){
        if(root == nullptr){
            return 0;
        }
        else{
            int left_sum = max(0, sum_path(root->left, maxi));
            int right_sum = max(0, sum_path(root->right, maxi));
            maxi = max(maxi , root->val + right_sum + left_sum);
            return root->val + max(left_sum,right_sum);
        }


    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        sum_path(root, maxi);
        return maxi;

    }
};
