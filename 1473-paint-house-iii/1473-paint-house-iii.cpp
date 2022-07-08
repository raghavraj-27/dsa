class Solution {
public:
    int dp[101][101][21] = {};
    int dfs(int ind, vector<int>& houses, vector<vector<int>>& cost, int target, int l_clr) {
        if(ind >= cost.size() or target < 0) {
            if(target == 0) return 0;
            return 1000001;
        }
        
        if(houses[ind] != 0) {
            return dfs(ind+1, houses, cost, target - (l_clr != houses[ind]), houses[ind]);
        }
        
        if(dp[ind][target][l_clr]) {
            return dp[ind][target][l_clr];
        }
        
        int res = 1000001;
        for(int j=1; j<=cost[ind].size(); j++) {
            res = min(res, cost[ind][j-1] + dfs(ind + 1, houses, cost, target - (l_clr != j), j));
        }
        
        return dp[ind][target][l_clr] = res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res = dfs(0, houses, cost, target, 0);
        if(res > 1000000) {
            return -1;
        }
        return res;
    }
};