class Solution {
public:
    int solve(int i, int j, int r, int c,
             vector<vector<int>> & grid, vector<vector<int>> & dp) 
    {
        if(i==r or j==c or i<0 or j<0)
            return 1000000;
        
        if(i==r-1 and j==c-1)
            return grid[i][j]; 
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int down = solve(i+1, j, r, c, grid, dp) + grid[i][j]; 
        int right = solve(i, j+1, r, c, grid, dp) + grid[i][j];
        
        return dp[i][j] = min(down, right); 
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(); 
        int c = grid[0].size(); 
        
        vector<vector<int>> dp(r, vector<int> (c, -1)); 
        
        return solve(0,0,r,c,grid,dp);
    }
};