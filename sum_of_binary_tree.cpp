int sum_bt(Node* root, int& sum){
    if(root == nullptr){
        return 0;
    }
    else{
        int ls = sum_bt(root->left, sum);
        int rs = sum_bt(root->right, sum);
        
        sum = root->key + ls + rs;
        
        return (ls +rs + root->key);
    }
    
}
long int sumBT(Node* root)
{
    // Code here
    int sum = 0;
    sum_bt(root, sum);
    return sum;
    
}
