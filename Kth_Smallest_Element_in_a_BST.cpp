class Solution {
public: 
    int solve(TreeNode* root, int& i, int k){
        if(root == nullptr){
            return -1;
        }

        int leftResult = solve(root->left, i , k);
        if(leftResult == k){
            return leftResult;
        }
        i++;

        if(i == k){
            return root->val;
        }

       return solve(root->right, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int i = 0;
        ans = solve(root, i, k);
        return ans;
    }
};
