class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindromic(int left, int right, string s) {
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    void makePatitions(int ind, string& s, vector<string> v) {
        if(ind >= s.size()) {
            ans.push_back(v);
        }
        
        for(int i=ind; i<s.size(); i++) {
            if(isPalindromic(ind, i, s)) {
                string str = s.substr(ind, i-ind+1);
                v.push_back(str);
                makePatitions(i+1, s, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        makePatitions(0, s, v);
        return ans;
    }
};