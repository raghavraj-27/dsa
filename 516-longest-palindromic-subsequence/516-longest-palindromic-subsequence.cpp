class Solution {
public:
    int calculate(int i, int j, string & s, vector<vector<int>> & dp)
    {
        if(i>j || i>=s.size() || j<0) return 0; 
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s.at(i) == s.at(j) and i+1 == j) return 2; 
        
        if(s.at(i) == s.at(j)) 
            dp[i][j] = 2 + calculate(i+1, j-1, s, dp); 
        else 
            dp[i][j] = max(calculate(i+1, j, s, dp), calculate(i, j-1, s, dp)); 
        
        return dp[i][j];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return calculate(0, n-1, s, dp);
    }
};