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
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        
        return f(1, c, cuts, dp);
    }
};