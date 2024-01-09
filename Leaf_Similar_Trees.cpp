#include <vector>
using namespace std;

class Solution {
public:
    void root_1(TreeNode* root1, vector<int>& v1){
        if (root1 == nullptr) {
            return;
        }

        if (root1->left == nullptr && root1->right == nullptr) {
            v1.push_back(root1->val);
            return;
        } else {
            root_1(root1->left, v1);
            root_1(root1->right, v1);
        }
    }

    void root_2(TreeNode* root2, vector<int>& v2){
        if (root2 == nullptr) {
            return;
        }

        if (root2->left == nullptr && root2->right == nullptr) {
            v2.push_back(root2->val);
            return;
        } else {
            root_2(root2->left, v2);
            root_2(root2->right, v2);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        root_1(root1, v1);
        root_2(root2, v2);

        if (v1.size() == v2.size()) {
            for (int i = 0; i < v1.size(); i++) {
                if (v1[i] != v2[i]) {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }
};
