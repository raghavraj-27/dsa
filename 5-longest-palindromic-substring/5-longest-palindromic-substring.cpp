class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size(), min_start=0, max_len=1;
        
        vector<vector<bool>> dp(size, vector<bool> (size, false));

        for(int i=0; i<size; i++) 
        {
            dp[i][i] = true;
            if(i!=size-1)
            {
                dp[i][i+1] = s.at(i)==s.at(i+1);
                if(dp[i][i+1])
                {
                    min_start = i; 
                    max_len = 2;
                }
            }    
        }   
        
        for(int gap=2; gap<size; gap++) 
        {
            for(int i=0, j=gap; j<size; j++, i++) 
            {
                dp[i][j] = s.at(i)==s.at(j) && dp[i+1][j-1];
                
                if(dp[i][j])
                {
                    min_start = i;
                    max_len = abs(j-i+1);
                }
            }
        }
        
        return s.substr(min_start, max_len);
    }
};