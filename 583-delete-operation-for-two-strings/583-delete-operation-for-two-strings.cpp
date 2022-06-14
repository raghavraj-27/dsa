class Solution {
public:
    int calc(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if(i>=word1.size()) {
            return word2.size()-j;
        }
        if(j>=word2.size()) {
            return word1.size()-i;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(word1[i] == word2[j]) {
            dp[i][j] = calc(i+1, j+1, word1, word2, dp);
        } else {
            int left = 1 + calc(i+1, j, word1, word2, dp);
            int right = 1 + calc(i, j+1, word1, word2, dp);
            dp[i][j] = min(left, right);
        }
        
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return calc(0, 0, word1, word2, dp);
    }
};