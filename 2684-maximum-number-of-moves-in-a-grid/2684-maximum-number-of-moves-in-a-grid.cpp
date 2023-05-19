class Solution {
public:
    int f(int x, int y, int prev, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if(x >= m or x < 0 or y >= n or y < 0) return 0;
        if(prev >= grid[x][y]) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        
        int val1 = f(x-1, y+1, grid[x][y], grid, m, n, dp);
        int val2 = f(x, y+1, grid[x][y], grid, m, n, dp);
        int val3 = f(x+1, y+1, grid[x][y], grid, m, n, dp);
        
        return dp[x][y] = max(val1, max(val2, val3)) + 1;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        for(int i=0; i<m; i++) {
            ans = max(ans, f(i, 0, -1, grid, m, n, dp));
        }
        
        return ans-1;
    }
};