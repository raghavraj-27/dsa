class Solution {
public:
    bool isSafe(vector<string>& board, int r, int c, int N) {
        int row = r, col = c;
        while(row >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
        }
        
        row = r;
        while(row >= 0 and col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }
        
        row = r; col = c;
        while(row >= 0 and col < N) {
            if(board[row][col] == 'Q') return false;
            row--; col++;
        }
        
        return true;
    }
    void getSolveNQueens(int ind, int N, vector<string>& board, vector<vector<string>>& ans) {
        if(ind >= N) {
            ans.push_back(board);
            return;
        }
        
        for(int c=0; c<N; c++) {
            if(board[ind][c] == '.') {
                if(isSafe(board, ind, c, N)) {
                    board[ind][c] = 'Q';
                    getSolveNQueens(ind+1, N, board, ans);
                    board[ind][c] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        getSolveNQueens(0, n, board, ans);
        return ans;
    }
};