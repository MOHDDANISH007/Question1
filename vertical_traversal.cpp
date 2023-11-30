#include <bits/stdc++.h>

using namespace std;

/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode()
    {
        if (left != nullptr)
        {
            delete left;
        }
        if (right != nullptr)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;

    // Write your code here.
    if (root == nullptr)
    {
        return ans;
    }

    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        TreeNode<int> *temp = p.first;
        int line = p.second.first;
        int level = p.second.second;

        nodes[line][level].push_back(temp->data);

        if (temp->left != nullptr)
        {
            q.push({temp->left, {line - 1, level + 1}});
        }

        if (temp->right != nullptr)
        {
            q.push({temp->right, {line + 1, level + 1}});
        }
    }

    // Extract values from the map in order
    for (auto &line : nodes)
    {
        for (auto &level : line.second)
        {
            for (auto &value : level.second)
            {
                ans.push_back(value);
            }
        }
    }

    return ans;
}
