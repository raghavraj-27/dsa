class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m, vector<int> (n));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int live = 0, died = 0;
                if(i>0) {
                    if(board[i-1][j] == 0) died++;
                    else live++;
                }
                if(j>0) {
                    if(board[i][j-1] == 0) died++;
                    else live++;
                }
                if(i<m-1) {
                    if(board[i+1][j] == 0) died++;
                    else live++;
                }
                if(j<n-1) {
                    if(board[i][j+1] == 0) died++;
                    else live++;
                }
                if(i>0 and j>0) {
                    if(board[i-1][j-1] == 0) died++;
                    else live++;
                }
                if(i>0 and j<n-1) {
                    if(board[i-1][j+1] == 0) died++;
                    else live++;
                }
                if(i<m-1 and j<n-1) {
                    if(board[i+1][j+1] == 0) died++;
                    else live++;
                }
                if(i<m-1 and j>0) {
                    if(board[i+1][j-1] == 0) died++;
                    else live++;
                }
                
                if(board[i][j] == 0 and live==3) {
                    ans[i][j] = 1;
                } 
                if(board[i][j] == 1) {
                    if(live < 2) ans[i][j] = 0;
                    else if(live == 2 or live == 3) ans[i][j] = 1;
                    else ans[i][j] = 0;
                }
            }
        }
        board = ans;
    }
};