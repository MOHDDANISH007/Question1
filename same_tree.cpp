// first approach and this approach is brute force T.C = o(n) and S.C = o(n)


#include <vector>

// /**
//  * Definition for a binary tree node.
//  */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void p_Tree(TreeNode* p, std::vector<int> &a){
        if (p == nullptr) {
            return;
        }
        p_Tree(p->left, a);
        a.push_back(p->val);
        p_Tree(p->right, a);
    }

    void q_Tree(TreeNode* q, std::vector<int> &b){
        if (q == nullptr) {
            return;
        }
        q_Tree(q->left, b);
        b.push_back(q->val);
        q_Tree(q->right, b);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a;
        vector<int> b;

        p_Tree(p, a);
        q_Tree(q, b);

        if (a.size() != b.size()) {
            return false;
        }

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }
};

