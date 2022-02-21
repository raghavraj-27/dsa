class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<unsigned long long int> dp(s.size(), 0); 
        unordered_set<string> dictionary; 
        
        for(auto word : wordDict) {
            dictionary.insert(word);
        }
        
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<=i; j++) {
                string str = s.substr(j, i-j+1); 
                if(dictionary.find(str) != dictionary.end()) {
                    if(j > 0) 
                        dp[i] += dp[j-1];
                    else
                        dp[i]++;
                }
            }
        }
        
        return dp[s.size() - 1] > 0;
    }
};