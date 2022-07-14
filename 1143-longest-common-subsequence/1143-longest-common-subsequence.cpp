class Solution {
public:
    int f(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j]) return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return f(text1.size()-1, text2.size()-1, text1, text2, dp);
    }
};