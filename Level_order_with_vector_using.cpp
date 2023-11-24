#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// printing the level order traversal..
void level_order_traversal(node* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    } else {
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int currentLevelSize = q.size();

            for (int i = 0; i < currentLevelSize; i++) {
                node* temp = q.front();
                q.pop();

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }

                if (temp->right != nullptr) {
                    q.push(temp->right);
                }

                ans.push_back(temp->data);
            }

            // Add a marker (e.g., -1) after each level to indicate the end of the level
            ans.push_back(-1);
        }
    }
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    vector<int> ans;
    level_order_traversal(root, ans);

    // Print the elements in the vector with new lines after each level
    for (int i : ans) {
        if (i == -1) {
            cout << endl;
        } else {
            cout << i << " ";
        }
    }

    return 0;
}

