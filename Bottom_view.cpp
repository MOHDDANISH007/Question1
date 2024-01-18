class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<pair<Node*, int>> q;
        map<int, int> mp;

        q.push({root, 0});

        while (!q.empty()) {
            Node* cur = q.front().first;
            int line = q.front().second;
            q.pop();

            // Update the value for the current line
            mp[line] = cur->data;

            if (cur->left != nullptr) {
                q.push({cur->left, line - 1});
            }
            if (cur->right != nullptr) {
                q.push({cur->right, line + 1});
            }
        }

        for (auto &it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
