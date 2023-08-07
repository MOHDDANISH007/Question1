class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    // Step 1: Transpose the matrix
    int n = matrix.size();
    int m = matrix[0].size();  
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < m; j++){
            swap(matrix[j][i], matrix[i][j]);
        }
    }

    // Step 2: Rotate 90 degrees by reversing each row
    for(int i = 0; i < n; i++){
        int left = 0;
        int right = m - 1;
        while(left < right){
            swap(matrix[i][left], matrix[i][right]);
            left++; 
            right--;
        }
    }
        
    }
};
