#include <climits>
#include <queue>
using namespace std;

// class TreeNode {
// public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int prev = INT_MIN;

        while (!q.empty()) {
            int size = q.size();

            if(level % 2 == 0){
                prev = INT_MIN;
            }
            else{
                prev = INT_MAX;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int element = node->val;

                if ((level % 2 == 0 && (element % 2 == 0 || element <= prev)) ||
                    (level % 2 == 1 && (element % 2 == 1 || element >= prev))) {
                    return false;
                }

                prev = element;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            level++;
        }

        return true;
    }
};
