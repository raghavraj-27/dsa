class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][51][51];
    
    Solution() {
        for(int i=0; i<51; i++) {
            for(int j=0; j<51; j++) {
                for(int k=0; k<51; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }
    
    int f(int i, int j, int m, int n, int maxMove, int dp[51][51][51]) {
        if(maxMove < 0) return 0;
        
        if(i<0 or i>=m or j<0 or j>=n) {
            return 1;
        }
        
        
        if(dp[i][j][maxMove] >= 0) return dp[i][j][maxMove];
        
        int a = f(i+1, j, m, n, maxMove-1, dp);
        int b = f(i-1, j, m, n, maxMove-1, dp);
        int c = f(i, j+1, m, n, maxMove-1, dp);
        int d = f(i, j-1, m, n, maxMove-1, dp);

        return dp[i][j][maxMove] = ((a + b)%mod + (c + d)%mod) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        
        return f(startRow, startColumn, m, n, maxMove, dp);
    }
};