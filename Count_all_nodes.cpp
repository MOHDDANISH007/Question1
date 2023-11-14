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
    int cnt = 0;   //step 1 -> Initialize cnt to 0

    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;  // step 2 -> Return 0 for null root
        }

        cnt++;  // step 3 -> Increment cnt for the current node
        countNodes(root->left);
        countNodes(root->right);

        return cnt;  // Return the total count
    }
};

