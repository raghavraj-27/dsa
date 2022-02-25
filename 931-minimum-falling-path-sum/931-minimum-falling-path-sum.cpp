class Solution {
public:
    int n;
    
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix.size()) return 100000;
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int way1 = matrix[i][j] + solve(i+1, j-1, matrix, dp);
        int way2 = matrix[i][j] + solve(i+1, j, matrix, dp);
        int way3 = matrix[i][j] + solve(i+1, j+1, matrix, dp);
        
        return dp[i][j] = min({way1, way2, way3});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            ans = min(ans, solve(0, i, matrix, dp));
        }
        
        return ans;
    }
};