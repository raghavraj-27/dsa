class Solution {
public:
    int coinChange(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if(amount == 0) return 0;
        
        if(i>=coins.size() or amount < 0) return 1000000;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int left = 1 + coinChange(i, coins, amount - coins[i], dp);
        int right = coinChange(i+1, coins, amount, dp);
        
        return dp[i][amount] = min(left, right);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        
        int res = coinChange(0, coins, amount, dp);
        
        return res > 100000 ? -1 : res;
    }
};