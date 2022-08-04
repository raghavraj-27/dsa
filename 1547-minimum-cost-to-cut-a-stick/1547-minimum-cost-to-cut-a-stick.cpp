class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;        
        for(int ind=i; ind<=j; ind++) {
            int len = cuts[j+1] - cuts[i-1];
            int left = f(i, ind-1, cuts, dp);
            int right = f(ind+1, j, cuts, dp);
            
            int cost = len + left + right;
            res = min(cost, res);
        }
        
        return dp[i][j] = res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        // for ease in calculating length of the rod
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        // for making sub problems independent,
        // once you make recursive tree you will understand this use cases
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), 0));
        
        for(int i=c; i>=1; i--) {
            for(int j=1; j<=c; j++) {
                if(i > j) continue;
                
                int res = INT_MAX;        
                for(int ind=i; ind<=j; ind++) {
                    int len = cuts[j+1] - cuts[i-1];
                    int left = dp[i][ind-1];
                    int right = dp[ind+1][j];

                    int cost = len + left + right;
                    res = min(cost, res);
                }

                dp[i][j] = res;
            }
        }
        
        return dp[1][c];
    }
};