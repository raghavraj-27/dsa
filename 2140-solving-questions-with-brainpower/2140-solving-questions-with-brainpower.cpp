class Solution {
public:
    long long solve(int ind, vector<vector<int>>& q, vector<long long>& dp) {
        if(ind == q.size()-1)
            return q[ind][0]; 
        
        if(ind >= q.size()) return 0; 
        
        if(dp[ind] != -1) return dp[ind]; 
        
        long long solved = q[ind][0] + solve(ind + q[ind][1] + 1, q, dp); 
        long long skiped = 0 + solve(ind + 1, q, dp);
        
        return dp[ind] = max(solved, skiped);
    }
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> dp(q.size(), -1);
        return solve(0, q, dp);
    }
};