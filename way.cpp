
#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/

vector<int> preorderTraversal(TreeNode* root)
{
    vector <int> p;
    if(root == nullptr){
        return p;
    }
    else{
        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            p.push_back(temp->val);

            if(temp->right != nullptr){
                st.push(temp->right);
            }
            if(temp->left != nullptr){
                st.push(temp->left);
            }
        }
        return p;
    }
}
