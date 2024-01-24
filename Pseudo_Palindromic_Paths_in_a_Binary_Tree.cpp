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
    int result = 0;
    
    void isPseudoPalindromicPaths(vector<int>& count){
        int oddFreq = 0;
        for(int i=0; i<count.size(); i++){
            if(count[i] % 2 != 0){
                oddFreq++;
            }
        }
        if(oddFreq <= 1){
            result++;
        }
    }
    
    void solve(TreeNode* root, vector<int>& count){
        if(root == nullptr){
            return;
        }

        count[root->val]++;
        if(root->left == nullptr && root->right == nullptr){
            isPseudoPalindromicPaths(count);
        }
        solve(root->left, count);
        solve(root->right, count);

        count[root->val]--;
    }
    
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> count(10, 0);
        solve(root, count);
        return result;
    }
};
