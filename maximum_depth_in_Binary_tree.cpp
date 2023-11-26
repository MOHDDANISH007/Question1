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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0; // Empty tree has depth 0
        }

        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            cnt++; // Increment depth after processing all nodes at the current level
        }
        return cnt;
    }
};



// Recursive way



#include <bits/stdc++.h> 
//TreeNode class definition
/*
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

*/

int findMaxDepth(TreeNode<int> *root) 
{
	//Write your code here.  
    if(root == nullptr){
        return 0;
    }
    else{
        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);

        return max(left,right)+1;
    }
}
