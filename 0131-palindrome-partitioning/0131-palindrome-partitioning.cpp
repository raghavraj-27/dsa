class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;
    
    bool isPalindrome(int l, int r, string s) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void f(int ind, string s) {
        if(ind >= s.size()) {
            ans.push_back(v);
        }
        
        for(int i=ind; i<s.size(); i++) {
            // string str = s.substr(i, ind-i+1);
            if(isPalindrome(ind, i, s)) {
                v.push_back(s.substr(ind, i-ind+1));
                f(i+1, s);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        f(0, s);
        return ans;
    }
};