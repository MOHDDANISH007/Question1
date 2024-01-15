#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void pre(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}
void inorder(node* root){
    if(root==nullptr){
        return;
    }
    pre(root->left);
    cout << root->data << " ";
    pre(root->right);
}

void postorder(node* root){
    if(root==nullptr){
        return;
    }
    pre(root->left);
    pre(root->right);
    cout << root->data << " ";
