class Solution {
public:
    // soln by self
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int> (6, 0));
        
        // for n = 1
        for(int i=1; i<=5; i++) {
            dp[1][i] = 1;
        }
        
        for(int i=2; i<=n; i++) {
            int sum = accumulate(dp[i-1].begin(), dp[i-1].end(), 0);
            int presum = 0;
            for(int j=1; j<=5; j++) {
                presum += dp[i-1][j-1];
                dp[i][j] = sum - presum;
                
                
            }
        }
    
        return accumulate(dp[n].begin(), dp[n].end(), 0);
    }
};