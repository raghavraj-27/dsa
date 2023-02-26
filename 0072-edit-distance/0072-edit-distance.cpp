class Solution {
public:
    int calc(int i1, int i2, string & word1, string & word2, vector<vector<int>> & dp) 
    {
        if(i1>=word1.size())
            return word2.size() - i2;
        
        if(i2>=word2.size()) 
            return word1.size() - i1;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(word1.at(i1) == word2.at(i2)) {
            dp[i1][i2] = calc(i1+1, i2+1, word1, word2, dp);
        }
        else {
            int insert = 1 + calc(i1, i2+1, word1, word2, dp);
            int replace = 1 + calc(i1+1, i2+1, word1, word2, dp);
            int remove = 1 + calc(i1+1, i2, word1, word2, dp);
            
            dp[i1][i2] = min(insert, min(replace, remove));
        }
        
        return dp[i1][i2];
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1)); 
        return calc(0,0,word1,word2,dp);
    }
};