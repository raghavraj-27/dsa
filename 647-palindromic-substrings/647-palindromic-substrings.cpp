class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int gap=0; gap<n; gap++) {
            for(int i=0, j=gap; j<n; j++, i++) {
                if(gap == 0) {
                    dp[i][j] = 1;
                } else if(gap == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    if(s[i] == s[j] and dp[i+1][j-1] == 1) {
                        dp[i][j] = 1;
                    } 
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += accumulate(dp[i].begin(), dp[i].end(), 0);
        }
        
        return ans;
    }
};