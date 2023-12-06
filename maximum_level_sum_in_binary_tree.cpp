class Solution {
public:
    int maxLevelSum(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int maxi = INT_MIN;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                sum += temp->data;

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
