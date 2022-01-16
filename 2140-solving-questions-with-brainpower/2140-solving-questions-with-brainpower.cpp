class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> dp(2e5+1); 
        for(int i=q.size()-1; i>=0; i--) {
            dp[i] = max(q[i][0] + dp[i + q[i][1] + 1], dp[i+1]);
        }
        
        return dp[0];
    }
};