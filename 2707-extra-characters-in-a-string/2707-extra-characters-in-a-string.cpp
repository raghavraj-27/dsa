class Solution {
public:
    int f(string s, unordered_set<string>& dict, unordered_map<string, int>& dp) {
        if(s == "") return 0;
        if(dp.find(s) != dp.end()) return dp[s];
        
        int res = 1 + f(s.substr(1), dict, dp);
        for(int i=0; i<s.size(); i++) {
            string new_str = s.substr(0, i+1);
            if(dict.find(new_str) != dict.end()) {
                res = min(res, f(s.substr(i+1), dict, dp));
            }
        }
        
        return dp[s] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> dp;
        unordered_set<string> dict;
        
        for(string str: dictionary) {
            dict.insert(str);
        }
        
        return f(s, dict, dp);
    }
};