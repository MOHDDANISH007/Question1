/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here

        vector<int> ans;

        if (root == nullptr)
        {
            return ans;
        }
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            Node *temp = q.front().first;
            int line = q.front().second;
            q.pop();

            if (mp.find(line) == mp.end())
            {
                mp[line] = temp->data;
            }

            if (temp->left != nullptr)
            {
                q.push({temp->left, line - 1});
            }

            if (temp->right != nullptr)
            {
                q.push({temp->right, line + 1});
            }
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
