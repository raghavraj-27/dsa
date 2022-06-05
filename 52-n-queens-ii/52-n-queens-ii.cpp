class Solution {
public:
    bool isSafe(int r, int c, int n, vector<string>& sub_ans) {
        int row = r, col = c;
        while(row >= 0) {
            if(sub_ans[row][col] == 'Q') return false;
            row--;
        }
        
        row = r, col = c;
        while(col >= 0 and row >= 0) {
            if(sub_ans[row][col] == 'Q') return false;
            row--; col--;
        }
        
        row = r, col = c;
        while(col < n and row >= 0) {
            if(sub_ans[row][col] == 'Q') return false;
            row--; col++;
        }
        
        return true;
    }
    
    void solve(int r, int n, vector<string>& sub_ans, vector<vector<string>>& ans) {
        if(r>=n) {
            ans.push_back(sub_ans);
            return;
        }        
        
        for(int i=0; i<n; i++) {
            if(isSafe(r, i, n, sub_ans)) {
                sub_ans[r][i] = 'Q';
                solve(r+1, n, sub_ans, ans);
                sub_ans[r][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> sub_ans(n, string(n, '.'));
        
        solve(0, n, sub_ans, ans);
        
        return ans.size();
    }
};