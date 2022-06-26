class Solution {
public:
    long long int mod = 1e9 + 7;
    int calc(long long int n, vector<long long int>& dp) 
    {
        if(n == 1) return dp[n] = 2;
        if(n == 2) return dp[n] = 3;
        
        if(dp[n] != -1) return dp[n];
        
        long long int pick = calc(n-2, dp);
        long long int nonpick = calc(n-1, dp);
        
        return dp[n] = (pick % mod + nonpick % mod) % mod;
    }
    
    int countHousePlacements(int n) {
        vector<long long int> dp(n+1, -1);
        long long int a = calc(n, dp);
        cout<<dp[n]<<",";
        return (dp[n]*dp[n]) % mod;
    }
};