class Solution {
public:
    int func(int i, vector<int>& cost, vector<int>& dp) {
        if(i>=cost.size()) return 0;
        if(i == cost.size()-1) return cost[i];
        
        if(dp[i] != -1) return dp[i];
        int val1 = cost[i] + func(i+1, cost, dp);
        int val2 = cost[i] + func(i+2, cost, dp);
        return dp[i] = min(val1, val2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        vector<int> dp(n, -1);
        return min(func(0, cost, dp), func(1, cost, dp));
    }
};