class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1; 
        
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    void f(int ind, string& s, vector<string>& v, vector<vector<string>>& ans) {
        if(ind >= s.size()) {
            ans.push_back(v);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            string str = s.substr(ind, i-ind+1);
            if(isPalindrome(str)) {
                v.push_back(str);
                f(i+1, s, v, ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        f(0, s, v, ans);
        
        return ans;
    }
};