class Solution {
public:
    bool f(string s, unordered_map<string, bool>& dp, unordered_set<string>& dict) {
        if(dict.find(s) != dict.end()) return true;

        if(dp.find(s) != dp.end()) return dp[s];

        for(int i=1; i<s.size(); i++) {
            string left = s.substr(0, i);
            if(dict.find(left) != dict.end() and f(s.substr(i), dp, dict)) {
                dp[s] = true;
                return true;
            }
        }

        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string str: wordDict) {
            dict.insert(str);
        }

        unordered_map<string, bool> dp;
        return f(s, dp, dict);
    }
};