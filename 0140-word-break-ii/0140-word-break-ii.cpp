class Solution {
public:
    void solve(int ind, string s, unordered_set<string>& dict, string sen, vector<string>& ans) {
        if(ind >= s.size()) {
            sen.pop_back();
            ans.push_back(sen);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            string str = s.substr(ind, i-ind+1);
            if(dict.find(str) != dict.end()) {
                solve(i+1, s, dict, sen + str + " ", ans);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string sen = "";
        
        unordered_set<string> dict;
        for(string s: wordDict) {
            dict.insert(s);
        }
        
        solve(0, s, dict, sen, ans);
        return ans;
    }
};