class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        vector<vector<int>> dir = {{0, 1}, {0,-1}, {1,0}, {-1, 0}};
        int maximum = 0;
        
        for(vector<int> d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            
            if(x>=0 and y>=0 and x<m and y<n and matrix[x][y] > matrix[i][j]) {
                int path = dfs(x, y, m, n, matrix, dp);
                maximum = max(maximum, path);
            }
        }
        
        return dp[i][j] = maximum + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        int longestPath = 1;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int path = dfs(i, j, m, n, matrix, dp);
                longestPath = max(path, longestPath);
            }
        }
        
        return longestPath;
    }
};