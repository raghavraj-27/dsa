class Solution {
public:
    int f(int i, int remWalls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if(remWalls <= 0) return 0;
        if(i < 0) return 1e9;
        
        if(dp[i][remWalls] != -1) return dp[i][remWalls];
        
        int cost1 = cost[i] + f(i-1, remWalls - (1 + time[i]), cost, time, dp);
        int cost2 = f(i-1, remWalls, cost, time, dp);
        
        return dp[i][remWalls] = min(cost1, cost2);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size(); 
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        
        return f(n-1, n, cost, time, dp);
    }
};