class Solution {
public:
    int countUniquePaths(int i, int j, int m, int n, vector<vector<int>> & dp)
    {
        if(i<0 or j<0 or i==m or j==n)
            return 0; 
        
        if(i==m-1 and j==n-1)
            return 1; 
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = countUniquePaths(i, j+1, m, n, dp); 
        int right = countUniquePaths(i+1, j, m, n, dp); 
        
        return dp[i][j] = left + right;
    }
    
    int uniquePaths(int m, int n) {
        if(m==1 and n==1)
            return 1;
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return countUniquePaths(0, 0, m, n, dp);
    }
};