class Solution {
public:
    void makeSentences(int ind, string& s, string sentence, unordered_set<string>& dict, vector<string> & ans) {
        if(ind >= s.size()) {
            ans.push_back(sentence);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            string word = s.substr(ind, i-ind+1);
            if(dict.find(word) != dict.end()) {
                if(ind!=0)
                    makeSentences(i+1, s, sentence + " " + word, dict, ans);
                else
                    makeSentences(i+1, s, sentence + word, dict, ans);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string sentence = "";
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        makeSentences(0, s, sentence, dict, ans);
        
        return ans;
    }
};