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
#include <bits/stdc++.h>
class Solution {
public:
    void construct_graph(unordered_map<int, vector<int>>& mp, TreeNode* root, int parent) {
        if (root == nullptr) {
            return;
        }

        if (parent != -1) {
            mp[root->val].push_back(parent);
        }

        if (root->left != nullptr) {
            mp[root->val].push_back(root->left->val);
        }

        if (root->right != nullptr) {
            mp[root->val].push_back(root->right->val);
        }

        construct_graph(mp, root->left, root->val);
        construct_graph(mp, root->right, root->val);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mp;

        if (root == nullptr) {
            return -1;
        }

        // Construct the graph
        construct_graph(mp, root, -1);

        // Applying BFS
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int minutes = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int current = q.front();
                q.pop();

                for (int neighbor : mp[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }

            minutes++;
        }

        return minutes - 1;
    }
};
