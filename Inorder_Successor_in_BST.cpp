class Solution {
public:
    Node* inOrderSuccessor(Node* root, Node* x) {
        Node* successor = nullptr;

        while (root != nullptr) {
            if (root->data > x->data) {
                // Update successor and move to the left subtree
                successor = root;
                root = root->left;
            } else {
                // Move to the right subtree
                root = root->right;
            }
        }

        return successor;
    }
};
