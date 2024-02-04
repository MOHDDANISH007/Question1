class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(root->left == nullptr){
            return root->right;
        }
        if(root->right == nullptr){
            return root->left;
        }
        TreeNode* left_child      = root->left;
        TreeNode* right_child     = root->right;
        TreeNode* left_last_child = find_last_child(root->left);
        left_last_child->right    = right_child;
        return  left_child;
    }

    TreeNode* find_last_child(TreeNode* root){
        if(root->right == nullptr){
            return root;
        }
        return find_last_child(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        while (root != nullptr) {
            if (root->val > key) {
                // it means go in the left part
                if (root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left);
                } else {
                    root = root->left;
                }
            } else {
                if (root->val < key) {
                    // it means go in the right part
                    if (root->right != nullptr && root->right->val == key) {
                        root->right = helper(root->right);
                    } else {
                        root = root->right;
                    }
                }
            }
        }
        return dummy;
    }
};
