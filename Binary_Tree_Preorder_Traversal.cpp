class Solution {
public:
    void preorder(const TreeNode* root, vector<int>& ans) const {
        // base case
        if (root == nullptr) {
            return;
        }

        // getting the value first then decide to go in left or right ..
        int num = root->val;
        ans.push_back(num);

        // going in left part until not get null value..
        preorder(root->left, ans);

        // going in right part until not get null value 
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(const TreeNode* root) const {
        if (root == nullptr) {
            return {}; // Return an empty vector when root is nullptr
        }

        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

