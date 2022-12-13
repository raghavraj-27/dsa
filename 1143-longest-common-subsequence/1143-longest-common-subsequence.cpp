class Solution {
public:
    int f(int i, string& s1, int j, string& s2, vector<vector<int>>& dp) {
        if(i < 0 or j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(i-1, s1, j-1, s2, dp);
        }
        
        int poss1 = f(i-1, s1, j, s2, dp);
        int poss2 = f(i, s1, j-1, s2, dp);
        return dp[i][j] = max(poss1, poss2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return f(n1-1, text1, n2-1, text2, dp);
    }
};