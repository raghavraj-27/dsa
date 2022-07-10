class Solution {
public:
    int solve(int i, int j, vector<int>& v, vector<vector<int>>& dp) {
        if(j < i+2) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MAX;
        for(int k=i+1; k<j; k++) {
            int cost = v[i]*v[k]*v[j] + solve(i, k, v, dp) + solve(k, j, v, dp);
            res = min(res, cost);
        }
        
        return dp[i][j] = res;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1)); 
        return solve(0, values.size()-1, values, dp);
    }
};