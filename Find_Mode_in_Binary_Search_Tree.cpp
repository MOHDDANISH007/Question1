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
    void preorder(TreeNode* root, map<int,int> &mp){
        if(root == nullptr){
            return;
        }
        else{
            //int num = root->val;
            mp[root->val]++;
            preorder(root->left, mp);
            preorder(root->right, mp);
        }
    }

    vector<int> findMode(TreeNode* root) {
        map <int,int> mp;
        preorder(root, mp);
        int max_frequecy_element = INT_MIN;

        vector <int> ans;

        for(auto it : mp){
            max_frequecy_element = max(max_frequecy_element, it.second);
        }

        for(auto it : mp){
