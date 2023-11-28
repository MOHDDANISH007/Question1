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
void zig_zag(TreeNode* root, vector<vector<int>>& result) { // Pass result by reference
    int L_to_R = 1;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();

            // int index = (L_to_R) ? i : size - 1 - i;
            if(L_to_R == 1){
                int index = i;
                ans[index] = temp->val;
            }
            else{
                int index = size - 1 - i;
                ans[index] = temp->val;
            }
            //ans[index] = temp->val;

            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        L_to_R = ~(L_to_R); // Toggle between true and false

        result.push_back(ans); // Push ans directly into result
    }
}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        } else {
            zig_zag(root, result);
            return result;
        }
    }
};

