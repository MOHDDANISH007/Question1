#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to map the frequencies of nodes in tree root2
    void mapping(Node* root2, unordered_map<int, int>& mp2) {
        if (root2 == nullptr) {
            return;
        } else {
            mapping(root2->left, mp2);
            mp2[root2->data]++;
            mapping(root2->right, mp2);
        }
    }

    // Helper function to count pairs satisfying the condition in tree root1
    void countPairsUtil(Node* root1, Node* root2, unordered_map<int, int>& mp2, int x, int& count) {
        if (root1 == nullptr) {
            return;
        }

        // Recursively process left subtree
        countPairsUtil(root1->left, root2, mp2, x, count);

        // Calculate the complement for the current node in root1
        int complement = x - root1->data;

        // Check if the complement is found in mp2
        if (mp2.find(complement) != mp2.end()) {
            // The complement is found in mp2, increment the count
            count++;
        } else {
            // The complement is not found in mp2, no valid pair
            // No need to increment the count in this case
        }

        // Recursively process right subtree
        countPairsUtil(root1->right, root2, mp2, x, count);
    }

    // Main function to count pairs with sum equal to x
    int countPairs(Node* root1, Node* root2, int x) {
        // Map the frequencies of nodes in tree root2
        unordered_map<int, int> mp2;
        mapping(root2, mp2);

        // Initialize the count variable
        int count = 0;

        // Count pairs in tree root1
        countPairsUtil(root1, root2, mp2, x, count);

        // Return the final count
        return count;
    }
};
