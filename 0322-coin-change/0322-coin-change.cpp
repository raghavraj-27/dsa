class Solution {
public:
    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // if(amount == 0) return 0;
        if(i == 0) {
            if(amount % coins[i] == 0) return amount / coins[i];
            else return 1e9;
        }
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int notTake = f(i-1, coins, amount, dp);
        int take = INT_MAX;
        if(coins[i] <= amount) {
            take = min(take, 1 + f(i, coins, amount - coins[i], dp));
        }
        
        return dp[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        
//         for(int i=0; i<n; i++) {
//             dp[i][0] = 0;
//             if(amoint)
//         }
        
//         for(int i=0; i<n; i++) {
//             for(int a=0; a<=amount; a++) {
//                 int notTake = (i==0 ? 1e9 : dp[i-1][a]);
//                 int take = INT_MAX;
//                 if(coins[i] <= a) {
//                     take = 1 + dp[i][a - coins[i]];
//                 }
                
//                 dp[i][a] = min(take, notTake);
//             }
//         }
        
        // return dp[n-1][amount];
        // int ans = dp[n-1][amount];
        int ans = f(coins.size()-1, coins, amount, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};