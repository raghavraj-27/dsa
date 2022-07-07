class Solution {
public:
    bool solve(int i, string s1, int j, string s2, int k, string s3, vector<vector<int>>& dp) {
        if(i >= s1.size() and j >= s2.size()) {
            return true;
        }
        
        if(i >= s1.size()) {
            if(s2[j] == s3[k]) 
                return solve(i, s1, j+1, s2, k+1, s3, dp);
            else
                return false;
        }
        
        if(j >= s2.size()) {
            if(s1[i] == s3[k])
                return solve(i+1, s1, j, s2, k+1, s3, dp);
            else
                return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool left = false, right = false;
        if(s1[i] == s3[k])
            left = solve(i+1, s1, j, s2, k+1, s3, dp);
        if(s2[j] == s3[k])
            right = solve(i, s1, j+1, s2, k+1, s3, dp);
        
        return dp[i][j] = left | right;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if(len1 + len2 != len3) return false;
        
        vector<vector<int>> dp(len1, vector<int> (len2, -1));
        return solve(0, s1, 0, s2, 0, s3, dp);
    }
};