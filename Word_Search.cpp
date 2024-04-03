	class Solution {
public:
    bool  dfs(vector<vector<char>>& board, int r, int c, string word, int windex){
        if(word.length() == windex){
            return true;
        }
        // here checking base case to going left,bottom,up,right and checking the element is equal or not...
        int row = board.size();
        int col = board[0].size();
        if(r < 0 || c < 0 || r >= row ||c >= col || board[r][c] != word[windex]){
            return false;
        }
        // mark visted if satisfy the above condition
        char ch = board[r][c];
        board[r][c] = ' ';
        if(dfs(board, r-1, c, word, windex+1) || dfs(board, r+1, c, word, windex+1) || dfs(board, r, c-1, word, windex+1) || dfs(board, r, c+1, word, windex+1)){
            return true;
        }

        // if the above conditon is not satisfy then going back make visted false or make it same
        board[r][c] = ch;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(board[r][c] == word[0]){
                    bool found =  dfs(board, r, c, word, 0);
                    if(found){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

