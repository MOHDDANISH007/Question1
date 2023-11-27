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




// Approach 2 optimal solution 



class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }

private:
    int height(TreeNode* root, int& maxi) {
        if (root == nullptr) {
            return 0;
        }

        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);

        maxi = std::max(maxi, lh + rh);

        return 1 + std::max(lh, rh);
    }
};
