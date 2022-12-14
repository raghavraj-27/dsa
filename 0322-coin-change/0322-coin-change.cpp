class Solution {
public:
    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(amount == 0) return 0;
        if(i < 0) return 1e9;
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int notTake = f(i-1, coins, amount, dp);
        int take = INT_MAX;
        if(coins[i] <= amount) {
            take = min(take, 1 + f(i, coins, amount - coins[i], dp));
        }
        
        return dp[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        
        int ans = f(coins.size()-1, coins, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};