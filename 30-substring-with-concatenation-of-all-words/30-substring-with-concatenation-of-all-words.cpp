class Solution {
public:
    bool check(string sub, map<string, int>& freq, int len) {
        map<string, int> seen;
        for(int i=0; i<sub.size(); i += len) {
            string str = sub.substr(i, len);
            seen[str]++;
        }
        return seen == freq;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> freq;
        for(string str: words) {
            freq[str]++;
        }
        
        vector<int> ans;
        int len = s.size(); 
        int wordsLen = words.size();
        int wordLen = words[0].size();
        
        for(int i=0; i <= len - wordsLen * wordLen; i++) {
            string str = s.substr(i, wordsLen * wordLen);
            if(check(str, freq, wordLen)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};