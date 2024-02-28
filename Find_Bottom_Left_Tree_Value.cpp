
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


    // This is BFS Code...
    int result = -1;
    void solve(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        int index = 0;

        for(int i = 0; i < size; i++){
            TreeNode* element = q.front();
            q.pop();

            ans[index++] = element->val;

            if(element->left){
                q.push(element->left);
            } 
            if(element->right){
                q.push(element->right);
            }
        }

        result = ans[0];  // Update result after processing each level
    }
}
    int maxi_depth = -1;
    
    // This is DFS code...
    void DFS(TreeNode* root, int depth){
        if(root == nullptr){
            return;
        }

        if(depth > maxi_depth){
            maxi_depth = depth;  
            result = root->val;
        }
        
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        else{
            DFS(root, 0);
            return result;
        }
            // else{
            //     solve(root, 0);
            //     return result;
            // }
        }
};
