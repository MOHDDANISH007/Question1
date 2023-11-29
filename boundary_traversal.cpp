/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
// A. going in left part and getting the nodes with exclusive nodes..

void printLeftBoundary(TreeNode<int> *root, vector<int> &ans) {
  if (root == NULL)
    return;
  // if root is leaf ,go back
  if (root->left == NULL && root->right == NULL) {
    return;
  }
  // using NLR ...
  ans.push_back(root->data);

  if (root->left) {
    printLeftBoundary(root->left, ans);
  } else {
    printLeftBoundary(root->right, ans);
  }
}
// B. going in left and right both part and getting the leaf nodes only...

void printLeafBoundary(TreeNode<int> *root, vector<int> &ans) {
  if (root == NULL)
    return;
  // if root is leaf ,store it else skip
  if (root->left == NULL && root->right == NULL) {
    ans.push_back(root->data);
  }
  printLeafBoundary(root->left, ans);
  printLeafBoundary(root->right, ans);
}
// C. going in right part and taking the value with the help of postorder traversal

void printRightBoundary(TreeNode<int> *root, vector<int> &ans) {
  if (root == NULL)
    return;
  // if root is leaf ,go back-->leave it for leafBoundary fxn
  if (root->left == NULL && root->right == NULL) {
    return;
  }
  if (root->right) {
    printRightBoundary(root->right, ans);
  } else {
    printRightBoundary(root->left, ans);
  }
  // wapas aate wqt push
  ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root) {
  vector<int> ans;
  if (root == NULL)
    return ans;

  ans.push_back(root->data);
  // Left
  printLeftBoundary(root->left, ans);
  // Leaf
  printLeafBoundary(root, ans);
  // Right
  printRightBoundary(root->right, ans);
  return ans;
}
