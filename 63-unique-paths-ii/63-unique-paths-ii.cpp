class Solution {
public:
    int calculate(int i, int j, int m, int n, vector<vector<int>> & dp, vector<vector<int>>& grid)
    {
        if(i>=m or j>=n)
            return 0;
        
        if(i==m-1 and j==n-1) 
            return 1; 
        
        if(grid[i][j] == 1) 
            return 0;
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int left = calculate(i, j+1, m, n, dp, grid);
        int right = calculate(i+1, j, m, n, dp, grid); 
        
        return dp[i][j] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return calculate(0, 0, m, n, dp, obstacleGrid);
    }
};