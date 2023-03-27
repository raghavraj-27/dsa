class Solution {
public:
    int m, n;
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == 0 and j == 0) {
            return grid[0][0];
        }
        
        if(i < 0 or j < 0 or i >= m or j >= n) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int choice1 = grid[i][j] + f(i, j-1, grid, dp);
        int choice2 = grid[i][j] + f(i-1, j, grid, dp);
        
        return dp[i][j] = min(choice1, choice2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return f(m-1, n-1, grid, dp);
    }
};