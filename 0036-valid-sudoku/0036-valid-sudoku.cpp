class Solution {
public:
    bool check(vector<vector<char>>& board, int r, int c, char ch) {
        board[r][c] = '.';
        for(int i=0; i<9; i++) {
            if(board[i][c] == ch) return false;
            if(board[r][i] == ch) return false;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3] == ch) return false;
        }
        board[r][c] = ch;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                
                if(check(board, i, j, board[i][j])) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};