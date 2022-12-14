class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        
        for(int a=0; a<=amount; a++) {
            if(a % coins[0] == 0) dp[0][a] = a / coins[0];
            else dp[0][a] = 1e9;
        }
        
        for(int i=1; i<n; i++) {
            for(int a=0; a<=amount; a++) {
                int notTake = dp[i-1][a];
                int take = INT_MAX;
                if(coins[i] <= a) {
                    take = 1 + dp[i][a - coins[i]];
                }
                
                dp[i][a] = min(take, notTake);
            }
        }
        
        // return dp[n-1][amount];
        int ans = dp[n-1][amount];
        // int ans = f(coins.size()-1, coins, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};