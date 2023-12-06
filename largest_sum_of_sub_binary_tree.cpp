// Brute force approach which u used vector & store the address of the nodess


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Assume Node structure looks like this
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
    // Constructor and other members if any
};

class Solution {
public:
    // Function to find the largest subtree sum.
    void solve(Node* root, vector<int>& pre) {
        if (root == nullptr) {
            return;
        } else {
            // Preorder traversal and inserting the values.
            pre.push_back(root->data);
            solve(root->left, pre);
            solve(root->right, pre);
        }
        return;
    }

    // Sum of subtree function.
    int subtreeSum(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->data + subtreeSum(node->left) + subtreeSum(node->right);
    }

    int findLargestSubtreeSum(Node* root) {
        // Write your code here.
        vector<int> pre;

        if (root == nullptr) {
            return 0;
        }
        solve(root, pre);

        // Sum of the largest subtree.
        int ans = INT_MIN;
        for (int i = 0; i < pre.size(); i++) {
            ans = max(ans, subtreeSum(root));
        }
        return ans;
    }
};

int main() {
    // Example usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    cout << "Largest Subtree Sum: " << solution.findLargestSubtreeSum(root) << endl;

    // Deallocate memory (assuming no smart pointers are used)
    // You may need to implement a proper destructor for your Node class
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}

// optimal approach



#include <iostream>
#include <vector>
#include <climits>

using namespace std;



#include <iostream>
#include <climits>

class Solution {
public:
    // Function to find the largest subtree sum.
    int findLargestSubtreeSum(Node* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }

        // Calculate subtree sums recursively
        int leftSum = findLargestSubtreeSum(root->left, ans);
        int rightSum = findLargestSubtreeSum(root->right, ans);

        // Update ans with the maximum subtree sum including the current node
        ans = max(ans, root->data + leftSum + rightSum);

        // Return the subtree sum rooted at the current node
        return root->data + leftSum + rightSum;
    }

    int findLargestSubtreeSum(Node* root) {
        // Initialize ans to the minimum value
        int ans = INT_MIN;

        // Find the largest subtree sum
        findLargestSubtreeSum(root, ans);

        return ans;
    }
};

