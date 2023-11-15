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
    void inorder(TreeNode* root, vector<int>& ans){
        // base case
        if(root == nullptr){
            return;
        }
        // going in left part until not get null value..
        inorder(root->left, ans);
        // getting the value ..
        int num = root->val;
        ans.push_back(num);

        //  going in right part until not get null value 
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {

        vector <int> ans;
        // step 2 -> create inorder function 
        inorder(root, ans);
        // step 3 -> return 
        return ans;
    }
};
