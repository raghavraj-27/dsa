class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool> (s.size(), false));
        int start = 0, max_len = 1;
        
        for(int g=0; g<s.size(); g++) {
            for(int i=0, j=g; j<s.size(); j++, i++) {
                if(g==0) {
                    dp[i][i] = true;
                } else if(g==1) {
                    dp[i][j] = (s[i]==s[j]);
                    // start = i; max_len = 2;
                } else {
                    dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
                    
//                     if(s[i] == s[j]) {
//                         if(dp[i+1][j-1]) {
                            
//                             // start = i, max_len = g+1;
//                             dp[i][j] = true;
//                         } else {
//                             dp[i][j] = false;
//                         }
//                     } else {
//                         dp[i][j] = false;
//                     }
                }
                
                if(dp[i][j] == true) {
                    start = i, max_len = abs(j-i+1);
                }
            }
        }
        
        return s.substr(start, max_len);
    }
};