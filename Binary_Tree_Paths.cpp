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
    void solve(TreeNode* root, string path, vector<string>& ans){
        if(root == nullptr){
            return;
        } else {
            // Convert the integer value to a string before pushing it into the vector
            path += to_string(root->val);

            // If it's a leaf node, add the path to the result vector
            if(root->left == nullptr && root->right == nullptr){
                ans.push_back(path);
            } else {
                path += "->";
                solve(root->left, path, ans);
                solve(root->right, path, ans);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        if(root == nullptr){
            return ans;
        }
        solve(root, path, ans);
        
       
        return ans;
    }
};
