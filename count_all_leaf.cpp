/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void inorder(BinaryTreeNode<int> *root, int &cnt){

    if(root == nullptr){ // step 1 = base case condition
        return;
    }
    
    // step 2 = count  all leaf nodes in left part
    inorder(root->left, cnt); 
    
    if(root->left == nullptr && root->right == nullptr){
        cnt++;
    }

    // step 3 = count  all leaf nodes in right part
    inorder(root->right, cnt);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int cnt = 0;
    
    inorder(root, cnt);
    return cnt; 
}
