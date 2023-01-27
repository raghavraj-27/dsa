class Solution {
public:
    unordered_set<string> store;
    bool f(int ind, string s) {
        if(ind >= s.size()) return true;
        
        for(int i=ind; i<s.size(); i++) {
            string sub = s.substr(ind, i-ind+1);
            if(store.find(sub) != store.end() and s != sub) {
                if(f(i+1, s)) return true;
                else continue;
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        store.clear();
        for(string s: words) {
            store.insert(s);
        }
        
        for(string s: words) {
            if(f(0, s)) ans.push_back(s);
        }
        return ans;
    }
};