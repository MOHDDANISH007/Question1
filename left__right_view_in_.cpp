vector<int> leftView(Node* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();
            if (i == 0) {
                ans.push_back(cur->data);  
            }
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
    }
    return ans;
}
