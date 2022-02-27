class Solution {
public:
    int calculate(int i, int j, string & text1, string & text2, vector<vector<int>> & dp)
    {
        if(i>=text1.size() || j>=text2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1.at(i) == text2.at(j)) 
            dp[i][j] = 1 + calculate(i+1, j+1, text1, text2, dp);
        else 
        {
            int left = calculate(i+1, j, text1, text2, dp); 
            int right = calculate(i, j+1, text1, text2, dp); 
            dp[i][j] = max(left, right);
        }
        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size(); 
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        
        return calculate(0,0,text1,text2,dp);
    }
};