class Solution {
public:
    void solve(Node* root, vector<int>& ans) {
        map<int, map<int, vector<int>>> mp; // Corrected map declaration
        queue<pair<Node*, pair<int, int>>> q; // Corrected queue declaration

        q.push({root, {0, 0}}); // Corrected push statement

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second.first;
            int level = it.second.second; // Corrected variable name

            mp[hd][level].push_back(node->data);

            if (node->left) { // Corrected condition
                q.push({node->left, {hd - 1, level + 1}}); // Corrected push statement
            }
            if (node->right) { // Corrected condition
                q.push({node->right, {hd + 1, level + 1}}); // Corrected push statement
            }
        }

        for (auto first : mp) {
            for (auto second : first.second) {
                for (auto val : second.second) {
                    ans.push_back(val);
                }
            }
        }
    }

    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        solve(root, ans);
        return ans;
    }
};



/* Inorder traveral code 

class Solution
{
public:
    void solve(Node* root, map<pair<int,int>, vector<int>>& mp, int hd, int level){
        if(root == nullptr){
            return;
        }
        else{
            // preorder traversal
            mp[{hd, level}].push_back(root->data); // Change {} to [] and use push_back instead of insert
            solve(root->left, mp, hd-1, level+1); // Change ans to mp
            solve(root->right, mp, hd+1, level+1); // Change ans to mp
        }
    }

    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // Your code here
        vector<int> ans;

        if(root == nullptr){
            return ans;
        }
        map<pair<int,int>, vector<int>> mp;

        solve(root, mp, 0, 0); // Change ans to mp
        for (auto it : mp) {
            vector<int> values = it.second;
            ans.insert(ans.end(), values.begin(), values.end());
        }
        return ans;
    }
};
*/
