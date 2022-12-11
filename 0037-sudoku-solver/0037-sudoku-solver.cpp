class Solution {
public:
    bool isValid(int r, int c, char val, vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            if(board[r][i] == val) return false;
            if(board[i][c] == val) return false;
            
            if(board[3*(r/3) + i/3][3*(c/3) + i%3] == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char c='1'; c<='9'; c++) {
                        if(isValid(i, j, c, board)) {
                            board[i][j] = c;
                            if(solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};